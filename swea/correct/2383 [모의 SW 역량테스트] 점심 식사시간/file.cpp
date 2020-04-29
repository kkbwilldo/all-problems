#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=13;
const int INF=987987987;

int testcase,size;
int minVal;
int selectStair[MAX];
int board[MAX][MAX];

struct person{
	int r,c,dist,startClk,endClk;
	bool done;
	person(int _r,int _c): \
	r(_r),c(_c),dist(-1),startClk(-1),endClk(-1),done(false){}
};

struct stair{
	int r,c,numStairs,numPeople;
	stair(int _r,int _c,int _numStairs): \
	r(_r),c(_c),numStairs(_numStairs),numPeople(0){}
};

vector <person> people;
vector <stair> stairs;
queue <int> waitList[2];

void CheckArrive(int Time){
	for(int i=0;i<people.size();i++){
		if(people[i].dist==Time){
			int idx=selectStair[i]-1;
			waitList[idx].push(i);
		}
	}
}

bool CheckAll(){
	for(int i=0;i<people.size();i++){
		if(people[i].done==false){
			return false;
		}
	}
	return true;
}

void EndMovement(int Time){
	for(int i=0;i<people.size();i++){
		if(people[i].endClk==Time){
			people[i].done=true;
			int idx=selectStair[i]-1;
			stairs[idx].numPeople--;
		}
	}
}

int GetDist(int pr,int pc,int sr,int sc){
	return abs(pr-sr)+abs(pc-sc)+1;//+1 안해줘서 틀림
}

void GoDown(){
	for(int i=0;i<people.size();i++){
		int idx=selectStair[i]-1;
		int pr=people[i].r;
		int pc=people[i].c;
		int sr=stairs[idx].r;
		int sc=stairs[idx].c;
		int dist=GetDist(pr,pc,sr,sc);
		people[i].dist=dist;
	}
	int Time=0;
	while(1){
		EndMovement(Time);
		if(CheckAll()) break;
		CheckArrive(Time);
		for(int i=0;i<2;i++){
			if(stairs[i].numPeople<3&&waitList[i].size()>0){
				while(!waitList[i].empty()){
					if(stairs[i].numPeople==3) break;
					int first=waitList[i].front();
					waitList[i].pop();
					people[first].startClk=Time;
					people[first].endClk=Time+stairs[i].numStairs;
					stairs[i].numPeople++;
				}
			}
		}
		Time++;
	}
	minVal=min(minVal,Time);
}

void AllCases(int depth){
	if(depth==people.size()){
		for(int i=0;i<2;i++){
			while(!waitList[i].empty()) waitList[i].pop();
			stairs[i].numPeople=0;
		}
		//ㅇㅕ기서 초기화 안해서 틀렸다
		for(int i=0;i<people.size();i++){
			people[i].done=false;
			people[i].dist=people[i].startClk=people[i].endClk=-1; // 이거!!
		}
		GoDown();
		return;
	}
	for(int i=1;i<=2;i++){
		selectStair[depth]=i;
		AllCases(depth+1);
	}
}

int main (){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		people.clear();
		stairs.clear();
		memset(board,0,sizeof(board));
		memset(selectStair,0,sizeof(selectStair));
		minVal=INF;
		cin>>size;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
				if(board[r][c]==1)
					people.push_back(person(r,c));
				else if(board[r][c]>=2)
					stairs.push_back(stair(r,c,board[r][c]));
			}
		}
		AllCases(0);
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
