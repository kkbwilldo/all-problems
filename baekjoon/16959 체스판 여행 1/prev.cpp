#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX=13;
const int INF=987987987;

int size,maxNum;
int answer;
int r,c,cnt,type,Next;
int dist[MAX*MAX];
int board[MAX][MAX];

int knightR[]={-2,-2,-1,1,2,2,-1,1};
int knightC[]={-1,1,-2,-2,-1,1,2,2};
int RookR[]={-1,1,0,0};
int RookC[]={0,0,-1,1};
int BishopR[]={-1,-1,1,1};
int BishopC[]={-1,1,-1,1};

queue <tuple<int,int,int,int,int> > q;

void Init(){
	for(int i=0;i<MAX*MAX;i++) dist[i]=INF;
	while(!q.empty()) q.pop();
}

void Move(int x,int y,int StartType){
	q.push(make_tuple(x,y,0,StartType,2));
	maxNum=2;
	while(!q.empty()){
		tie(r,c,cnt,type,Next)=q.front();
		q.pop();
		if(Next+1<maxNum) continue;
		if(dist[Next]<cnt) continue;
		if(board[r][c]==Next&&Next==size*size){
			answer=min(answer,cnt);
			//cout<<"cur: "<<Next-1<<" next: "<<Next<<" cnt: "<<cnt<<" type: "<<type<<endl;
			break;
		}
		if(Next>=size*size+1) break;
		if(board[r][c]==Next){
			maxNum=Next+1;
			dist[Next]=cnt;
			q.push(make_tuple(r,c,cnt,type,Next+1));
			//cout<<"cur: "<<Next-1<<" next: "<<Next<<" cnt: "<<cnt<<" type: "<<type<<endl;
			continue;
		}
		// 말 바꾸기
		for(int i=0;i<3;i++){
			if(type==i) continue;
			q.push(make_tuple(r,c,cnt+1,i,Next));
		}
		// 나이트
		if(type==0){
			for(int i=0;i<8;i++){
				int nr=r+knightR[i];
				int nc=c+knightC[i];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				q.push(make_tuple(nr,nc,cnt+1,type,Next));
			}
		}
		// 룩
		else if(type==1){
			for(int i=0;i<4;i++){
				int nr=r+RookR[i];
				int nc=c+RookC[i];
				while(0<=nr&&nr<size&&0<=nc&&nc<size){
					q.push(make_tuple(nr,nc,cnt+1,type,Next));
					nr+=RookR[i];
					nc+=RookC[i];
				}
			}
		}
		// 비숍 
		else if(type==2){
			for(int i=0;i<4;i++){
				int nr=r+BishopR[i];
				int nc=c+BishopC[i];
				while(0<=nr&&nr<size&&0<=nc&&nc<size){
					q.push(make_tuple(nr,nc,cnt+1,type,Next));
					nr+=BishopR[i];
					nc+=BishopC[i];
				}
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	//freopen("input.txt","r",stdin);
	
	int StartR,StartC;
	answer=INF;
	cin>>size;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>board[r][c];
			if(board[r][c]==1){
				StartR=r;
				StartC=c;
			}
		}
	}
	for(int i=0;i<3;i++){
		Init();
		Move(StartR,StartC,i);
		//cout<<endl;
	}
	cout<<answer<<endl;
	return 0;
}
