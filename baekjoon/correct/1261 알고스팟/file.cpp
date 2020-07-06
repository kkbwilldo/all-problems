#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX=110;
const int INF=987987987;

int ROW,COL;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
int dists[MAX][MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>COL>>ROW;
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
			dists[r][c]=INF;
		}
	}
	
	int StartR=0,StartC=0;
	int EndR=ROW-1,EndC=COL-1;
	dists[StartR][StartC]=0;
	
	priority_queue <tuple<int,int,int> > q;
	q.push(make_tuple(0,StartR,StartC));
	while(!q.empty()){
		int dist,r,c;
		tie(dist,r,c)=q.top();
		q.pop();
		dist*=-1;
		if(dist>dists[r][c]) continue;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			int cost=board[nr][nc]-'0';
			if(dists[nr][nc]>dist+cost){
				dists[nr][nc]=dist+cost;
				q.push(make_tuple(-dists[nr][nc],nr,nc));
			}
		}
	}
	cout<<dists[EndR][EndC]<<endl;
	return 0;
}
