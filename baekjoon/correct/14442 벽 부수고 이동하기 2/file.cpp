#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int INF=987987978;
const int MAX=1010;

char board[MAX][MAX];

int ROW,COL,Break,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int visited[MAX][MAX][15];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	answer=INF;
	memset(visited,-1,sizeof(visited));
	cin>>ROW>>COL>>Break;
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
		}
	}
	
	int StartR=0;
	int StartC=0;
	queue <tuple<int,int,int,int> > q;
	q.push(make_tuple(StartR,StartC,0,1));
	visited[StartR][StartC][0]=true;
	
	while(!q.empty()){
		int r,c,numBreaks,cnt;
		tie(r,c,numBreaks,cnt)=q.front();
		q.pop();
		if(r==ROW-1&&c==COL-1){
			answer=cnt;
			break;
		}
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int ncnt=cnt+1;
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(board[nr][nc]=='1'){
				if(numBreaks>=Break) continue;
				if(visited[nr][nc][numBreaks+1]!=-1) continue;
				visited[nr][nc][numBreaks+1]=ncnt;
				q.push(make_tuple(nr,nc,numBreaks+1,ncnt));
			}
			else{
				if(visited[nr][nc][numBreaks]!=-1) continue;
				visited[nr][nc][numBreaks]=ncnt;
				q.push(make_tuple(nr,nc,numBreaks,ncnt));
			}
		}
	}
	if(answer==INF) answer=-1;
	cout<<answer<<endl;
	return 0;
}
