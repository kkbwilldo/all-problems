#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=1001;
int ROW,COL,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
bool visited[MAX][MAX][2];

void bfs(){
	int StartR=0,StartC=0;
	int EndR=ROW-1,EndC=COL-1;
	visited[StartR][StartC][0]=true;
	queue <tuple<int,int,int,int> > q;
	q.push(make_tuple(StartR,StartC,0,1));
	while(!q.empty()){
		int r,c,collapse,cnt;
		tie(r,c,collapse,cnt)=q.front();
		q.pop();
		if(r==EndR&&c==EndC){
			answer=cnt;
			return;
		}
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(board[nr][nc]=='1'){
				if(collapse>=1) continue;
				visited[nr][nc][1]=true;
				q.push(make_tuple(nr,nc,1,cnt+1));
			}
			else{
				if(visited[nr][nc][collapse]) continue;
				visited[nr][nc][collapse]=true;
				q.push(make_tuple(nr,nc,collapse,cnt+1));
			}
		}
	}
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
	bfs();
	if(answer==0) answer=-1;
	cout<<answer<<endl;
	return 0;
}
