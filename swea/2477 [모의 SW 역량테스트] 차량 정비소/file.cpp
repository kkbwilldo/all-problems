#include <iostream>
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
	int elapseTime;
	bool empty;
};

struct repairDesk{
	int elapseTime;
	bool empty;
};

customer customers[CUSTOMERS];
receptDesk receptDesks[DESKS];
repairDesk repairDesks[DESKS];

queue <int> receptWaitingLine,repairWaitingLine;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numRecepts>>numRepairs>>numCustomers>>receptNum>>repairNum;
		for(int i=0;i<numRecepts;i++){
			int Time;
			cin>>Time;
			receptDesks[i].elapseTime=Time;
			receptDesks[i].empty=true;
		}
		for(int i=0;i<numRepairs;i++){
			int Time;
			cin>>Time;
			repairDesks[i].elapseTime=Time;
			repairDesks[i].empty=true;
		}
		for(int i=0;i<numCustomers;i++){
			int Time;
			cin>>Time;
			customers[i].arrive=Time;
			customers[i].customerNum=i;
			customers[i].receptNum=customers[i].repairNum=-1;
			customers[i].receptStart=customers[i].receptEnd=-1;
			customers[i].repairStart=customers[i].repairEnd=-1;
			done=false;
		}
		
		int Time=0;
		while(1){
			MarkDone(Time);
			if(AllDone(Time)) break;
			PushToWait(Time,"recept");
			availableRecept=GetAvailable("recept");
			if(availableRecept>0&&receptWaitingLine.size()>0){
				while(!receptWaitingLine.empty()){
					if(availableRecept<=0) break;
					int frontCustomer=receptWaitingLine.front();
					GetService(Time,frontCustomer,"recept");
					
				}
			}
		}
	}
	
	return 0;
}
