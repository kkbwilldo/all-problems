#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 22;
const int RANGE = 23;

int testcase,size,profit;
int numHouses,cost,maxVal;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int costs[RANGE];
int maxHouses[RANGE];
int map[MAX][MAX];
bool visited[MAX][MAX];

int secure(int startR,int startC){
	memset(visited,0,sizeof(visited));
	int cnt=0;
	queue <pair<pair<int,int>,int> > q;
	visited[startR][startC]=true;
	q.push(make_pair(make_pair(startR,startC),k));
	while(!q.empty()){
		int r=q.front().first.first;
		int c=q.front().first.second;
		int dist=q.front().second;
		q.pop();
		if(map[r][c]==1) cnt++;
		if(dist>size+1) continue;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_pair(make_pair(nr,nc),dist-1));
		}
	}
	return cnt;
}

int calc(int numHouses,int cost){
	return numHouses*profit-cost;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=1;i<RANGE;i++) costs[i]=((i-1)*(i-1))+(i*i);
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>profit;
		maxVal=0;
		memset(map,0,sizeof(map));
		memset(maxHouses,0,sizeof(maxHouses));
		maxHouses[1]=1;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cin>>map[i][j];
			}
		}
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				for(int k=1;k<size+1;k++){
					numHouses=secure(k,r,c);
					cost=calc(numHouses,costs[k]);
					if(cost>=0){
						maxHouses[k]=max(maxHouses[k],numHouses);
					}
				}
			}
		}
		for(int k=1;k<RANGE;k++){
			maxVal=max(maxHouses[k],maxVal);
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
