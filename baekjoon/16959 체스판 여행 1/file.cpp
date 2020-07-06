#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX=13;

int size,answer;
int r,c,moveCnt,Next,type;
int board[MAX][MAX];
bool visited[MAX][MAX][MAX*MAX][3];

int KnightR[]={-2,-2,-1,1,2,2,-1,1};
int KnightC[]={-1,1,-2,-2,-1,1,2,2};
int RookR[]={-1,1,0,0};
int RookC[]={0,0,-1,1};
int BishopR[]={-1,-1,1,1};
int BishopC[]={-1,1,-1,1};

void Move(int StartR,int StartC,int StartType){
	visited[StartR][StartC][2][StartType]=true;
	queue <tuple<int,int,int,int,int> > q; // r,c,moveCnt,Next,type
	q.push(make_tuple(StartR,StartC,0,2,StartType));
	while(!q.empty()){
		tie(r,c,moveCnt,Next,type)=q.front();
		q.pop();
		if(Next==size*size+1){
			answer=moveCnt;
			break;
		}
		// 다음 번호 갱신
		if(board[r][c]==Next){
			if(visited[r][c][Next+1][type]) continue;
			visited[r][c][Next+1][type]=true;
			q.push(make_tuple(r,c,moveCnt,Next+1,type));
			continue;
		}
		// 말 바꾸기
		for(int i=0;i<3;i++){
			if(type==i) continue;
			q.push(make_tuple(r,c,moveCnt+1,Next,i));
		}
		// 나이트
		if(type==0){
			for(int i=0;i<8;i++){
				int nr=r+KnightR[i];
				int nc=c+KnightC[i];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				if(visited[nr][nc][Next][type]) continue;
				visited[nr][nc][Next][type]=true;
				q.push(make_tuple(nr,nc,moveCnt+1,Next,type));
			}
		}
		// 룩
		else if(type==1){
			for(int i=0;i<4;i++){
				int nr=r+RookR[i];
				int nc=c+RookC[i];
				while(0<=nr&&nr<size&&0<=nc&&nc<size){
					if(!visited[nr][nc][Next][type]){
						visited[nr][nc][Next][type]=true;
						q.push(make_tuple(nr,nc,moveCnt+1,Next,type));
						nr+=RookR[i];
						nc+=RookC[i];
					}
				}
			}
		}
		// 비숍 
		else if(type==2){
			for(int i=0;i<4;i++){
				int nr=r+BishopR[i];
				int nc=c+BishopC[i];
				while(0<=nr&&nr<size&&0<=nc&&nc<size){
					if(!visited[nr][nc][Next][type]){
						visited[nr][nc][Next][type]=true;
						q.push(make_tuple(nr,nc,moveCnt+1,Next,type));
						nr+=BishopR[i];
						nc+=BishopC[i];
					}
				}
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int StartR,StartC;
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
	for(int i=0;i<3;i++) Move(StartR,StartC,i);
	cout<<answer<<endl;
	return 0;
}
