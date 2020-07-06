#include <iostream>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=110;

int ROW,COL,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
bool visited[MAX][MAX];

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
	
	queue <tuple<int,int,int> > q;
	visited[0][0]=true;
	q.push(make_tuple(0,0,1));
	while(!q.empty()){
		int r,c,cnt;
		tie(r,c,cnt)=q.front();
		q.pop();
		if(r==ROW-1&&c==COL-1){
			answer=cnt;
			break;
		}
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(board[nr][nc]!='1') continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_tuple(nr,nc,cnt+1));
		}
	}
	
	cout<<answer<<endl;
	return 0;
}
