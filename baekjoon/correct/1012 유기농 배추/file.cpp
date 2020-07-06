#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=55;
int ROW,COL,numCabages;
int testcase,answer;
int r,c;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int StartR,int StartC){
	visited[StartR][StartC]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(StartR,StartC));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(board[nr][nc]!=1) continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_pair(nr,nc));
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		memset(visited,0,sizeof(visited));
		answer=0;
		cin>>COL>>ROW>>numCabages;
		for(int i=0;i<numCabages;i++){
			cin>>c>>r;
			board[r][c]=1;
		}
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				if(board[r][c]==1&&!visited[r][c]){
					bfs(r,c);
					answer++;
				}
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}
