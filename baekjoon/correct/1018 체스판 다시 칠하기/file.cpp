#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=55;
const int INF=987987987;

int ROW,COL,answer;
char cells[2]={'W','B'};
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
bool visited[MAX][MAX];

int Check(int StartR,int StartC,char StartCell){
	int numCells=0;
	memset(visited,0,sizeof(visited));
	visited[StartR][StartC]=true;
	queue <tuple<int,int,char> > q;
	q.push(make_tuple(StartR,StartC,StartCell));
	while(!q.empty()){
		int r,c,curCell;
		tie(r,c,curCell)=q.front();
		q.pop();
		if(curCell!=board[r][c]) numCells++;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int ncell=curCell=='W'?'B':'W';
			if(nr<StartR||nr>StartR+7||nc<StartC||nc>StartC+7) continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_tuple(nr,nc,ncell));
		}
	}
	return numCells;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
		}
	}
	
	answer=INF;
	
	for(int r=0;r<=ROW-8;r++){
		for(int c=0;c<=COL-8;c++){
			for(int i=0;i<2;i++){
				int result=Check(r,c,cells[i]);
				answer=min(answer,result);
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}
