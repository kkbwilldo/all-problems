#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

const int MAX=110;
const int INF=987987987;

int testcase;
int size;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
int dist[MAX][MAX];
string num;

void Dijkstra(){
	int StartR=0,StartC=0;
	dist[StartR][StartC]=0;
	priority_queue <tuple<int,int,int> > pq;
	pq.push(make_tuple(0,StartR,StartC));
	while(!pq.empty()){
		int cost,r,c;
		tie(cost,r,c)=pq.top();
		cost*=-1;
		pq.pop();
		if(dist[r][c]<cost) continue;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(dist[nr][nc]<=cost+board[nr][nc]) continue;
			dist[nr][nc]=cost+board[nr][nc];
			pq.push(make_tuple(-dist[nr][nc],nr,nc));
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size;
		memset(board,0,sizeof(board));
		for(int r=0;r<size;r++){
			cin>>num;
			for(int c=0;c<size;c++){
				dist[r][c]=INF;
				board[r][c]=num[c]-'0'; // '0' 안빼줘서 틀림 
			}
		}
		Dijkstra();
		cout<<"#"<<test<<" "<<dist[size-1][size-1]<<endl;
	}
	return 0;
}
