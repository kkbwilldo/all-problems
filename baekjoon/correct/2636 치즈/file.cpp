#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 110;
const int INF = 987987987;

int ROW,COL,maxVal,cnt;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
int dists[MAX][MAX];
bool zeros[MAX][MAX];

void dijkstra(){
	int StartR=0;int StartC=0;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			dists[r][c]=INF;
		}
	}
	dists[StartR][StartC]=0;
	priority_queue <pair<int,pair<int,int> > > pq;
	pq.push(make_pair(0,make_pair(StartR,StartC)));
	while(!pq.empty()){
		int cost = -pq.top().first;
		int r = pq.top().second.first;
		int c= pq.top().second.second;
		pq.pop();
		if(dists[r][c]<cost) continue;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int nextDist=cost;
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(map[nr][nc]==1){
				if(map[r][c]==0||map[r][c]==1){
					nextDist++;
				}
			}
			if(dists[nr][nc]>nextDist){
				dists[nr][nc]=nextDist;
				pq.push(make_pair(-nextDist,make_pair(nr,nc)));
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
			cin>>map[r][c];
			if(map[r][c]==0) zeros[r][c]=true;
		}
	}
	
	dijkstra();
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(maxVal<dists[r][c]&&!zeros[r][c]){
				maxVal=dists[r][c];
				cnt=1;
			}
			else if(maxVal==dists[r][c]&&!zeros[r][c]){
				cnt++;
			}
		}
	}
	
	cout<<maxVal<<endl<<cnt<<endl;
	return 0;
}
