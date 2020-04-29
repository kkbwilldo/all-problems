#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int CUSTOMERS=1010;
const int DESKS=12;

int testcase,answer;
int numRecepts,numRepairs;
int numCustomers;
int receptNum,repairNum;

struct customer{
	int arrive,customerNum;
	int receptNum,repairNum;
	int receptStart,receptEnd;
	int repairStart,repairEnd;
	bool done;
};

struct receptDesk{
	int Time;
	bool empty;
};

struct repairDesk{
	int Time;
	bool empty;
};

customer customers[CUSTOMERS];
receptDesk receptDesks[DESKS];
repairDesk repairDesks[DESKS];

queue <int> receptWaitingLine,repairWaitingLine;

void MarkDone(int Time){
	for(int i=1;i<=numCustomers;i++){
		if(customers[i].receptEnd==Time)
			receptDesks[customers[i].receptNum].empty=true;
		if(customers[i].repairEnd==Time){
			repairDesks[customers[i].repairNum].empty=true;
			customers[i].done=true; // ㅇㅣ거 안해서 틀렸다!!!!
		}
	}
}

void PrintDone(int Time){
	for(int i=1;i<=numCustomers;i++){
		cout<<customers[i].done<<" ";
	}
	cout<<endl;
}

bool AllDone(int Time){
	for(int i=1;i<=numCustomers;i++){
		if(customers[i].done==false) return false;
	}
	return true;
}

bool receptSort(const int &a,const int &b){
	return customers[a].customerNum<customers[b].customerNum;
}

bool repairSort(const int &a,const int &b){
	return customers[a].receptNum<customers[b].receptNum;
}

void PushToWait(int Time,string type){
	vector <int> arriveList;
	if(type=="recept"){
		for(int i=1;i<=numCustomers;i++){
			if(customers[i].arrive==Time) arriveList.push_back(i);
		}
		sort(arriveList.begin(),arriveList.end(),receptSort);
		for(int i=0;i<arriveList.size();i++)
			receptWaitingLine.push(arriveList[i]);
	}
	else if(type=="repair"){
		for(int i=1;i<=numCustomers;i++){
			if(customers[i].repairStart==Time) arriveList.push_back(i);
		}
		sort(arriveList.begin(),arriveList.end(),repairSort);
		for(int i=0;i<arriveList.size();i++)
			repairWaitingLine.push(arriveList[i]);
	}
}

int GetAvailable(string type){
	int cnt=0;
	if(type=="recept"){
		for(int i=1;i<=numRecepts;i++){
			if(receptDesks[i].empty) cnt++;
		}
	}
	else if(type=="repair"){
		for(int i=1;i<=numRepairs;i++){
			if(repairDesks[i].empty) cnt++;
		}
	}
	return cnt;
}

void GetService(int Time,int customerNum,string type){
	if(type=="recept"){
		for(int i=1;i<=numRecepts;i++){
			if(receptDesks[i].empty){
				receptDesks[i].empty=false;
				customers[customerNum].receptNum=i;
				customers[customerNum].receptStart=Time;
				customers[customerNum].receptEnd=Time+receptDesks[i].Time;
				customers[customerNum].repairStart=Time+receptDesks[i].Time;
				return;
			}
		}
	}
	else if(type=="repair"){
		for(int i=1;i<=numRepairs;i++){
			if(repairDesks[i].empty){
				repairDesks[i].empty=false;
				customers[customerNum].repairNum=i;
				customers[customerNum].repairStart=Time;
				customers[customerNum].repairEnd=Time+repairDesks[i].Time;
				return;
			}
		}
	}
}

void Init(){
	answer=0;
	while(!receptWaitingLine.empty()) receptWaitingLine.pop();
	while(!repairWaitingLine.empty()) repairWaitingLine.pop();
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		Init();
		cin>>numRecepts>>numRepairs>>numCustomers>>receptNum>>repairNum;
		for(int i=1;i<=numRecepts;i++){
			int Time;
			cin>>Time;
			receptDesks[i].Time=Time;
			receptDesks[i].empty=true;
		}
		for(int i=1;i<=numRepairs;i++){
			int Time;
			cin>>Time;
			repairDesks[i].Time=Time;
			repairDesks[i].empty=true;
		}
		for(int i=1;i<=numCustomers;i++){
			int Time;
			cin>>Time;
			customers[i].arrive=Time;
			customers[i].customerNum=i;
			customers[i].receptNum=customers[i].repairNum=-1;
			customers[i].receptStart=customers[i].receptEnd=-1;
			customers[i].repairStart=customers[i].repairEnd=-1;
			customers[i].done=false;
		}
		
		int Time=0;
		//PrintDone(Time);
		while(1){
			MarkDone(Time); // 접수 및 정비 끝낸 사람 done 표시
			//PrintDone(Time);
			if(AllDone(Time)) break; // 모든 고객이 서비스를 모두 받았으면
			PushToWait(Time,"recept"); // 현재 시각에 도착하는 고객을 대기 큐에 푸쉬
			int availableRecepts=GetAvailable("recept"); // 사용 가능한 접수 창구 수
			// 사용 가능한 접수 창구가 존재 & 대기중인 손님 존재 
			if(availableRecepts>0&&!receptWaitingLine.empty()){ 
				while(!receptWaitingLine.empty()){ // 대기열이 없어질 때까지
					if(availableRecepts<=0) break; // 사용가능한 접수 창구 없으면
					int frontCustomer=receptWaitingLine.front();
					GetService(Time,frontCustomer,"recept"); // 대기열 맨 앞 손님 서비스
					receptWaitingLine.pop();
					availableRecepts--;
				}
			}
			PushToWait(Time,"repair");
			int availableRepairs=GetAvailable("repair");
			if(availableRepairs>0&&!repairWaitingLine.empty()){
				while(!repairWaitingLine.empty()){
					if(availableRepairs<=0) break;
					int frontCustomer=repairWaitingLine.front();
					GetService(Time,frontCustomer,"repair");
					repairWaitingLine.pop();
					availableRepairs--;
				}
			}
			Time++;
		}
		//cout<<"Time: "<<Time<<endl;
		for(int i=1;i<=numCustomers;i++){
			if(customers[i].receptNum==receptNum){ // 정답 접수 창구 사용한 고객
				if(customers[i].repairNum==repairNum){ // 정답 정비 창구 사용한 고객
					answer+=i;
				}
			}
		}
		if(answer==0) answer=-1;
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
