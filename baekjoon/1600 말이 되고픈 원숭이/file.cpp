#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX=210;

int numJumps,ROW,COL;
int dr[]={-2,-2,-1,-1,1,1,2,2};
int dc[]={-1,1,-2,2,-2,2,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX][31];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numJumps>>COL>>ROW;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
		}
	}
	
	int StartR=0,StartC=0,StartJ=0;
	int EndR=ROW-1,EndC=COL-1;
	visited[StartR][StartC][0]=true;
	queue <tuple<int,int,int> > q;
	q.push(make_tuple(StartR,StartC,StartJ));
	while(!q.empty()){
		int r,c,jump;
		tie(r,c,jump)=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int njump=jump+1;
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc][])
		}
	}
	return 0;
}
