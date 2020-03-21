#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

const int MAX = 130;
int mapSize,testcase;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int map[MAX][MAX];
int costMap[MAX][MAX];

void BFS(){
	for(int i=0;i<mapSize;i++){
		for(int j=0;j<mapSize;j++){
			costMap[i][j]=987987987;
		}
	}
	queue <pair<int,int> > q;
	q.push(make_pair(0,0));
	costMap[0][0]=map[0][0];
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(nr<0||nr>=mapSize||nc<0||nc>=mapSize) continue;
			if(costMap[nr][nc]>costMap[r][c]+map[nr][nc]){
				costMap[nr][nc]=costMap[r][c]+map[nr][nc];
				q.push(make_pair(nr,nc));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//freopen("input.txt","r",stdin);
	cin>>mapSize;
	while(mapSize){
		testcase++;
		memset(map,0,sizeof(map));
		for(int i=0;i<mapSize;i++){
			for(int j=0;j<mapSize;j++){
				cin>>map[i][j];
			}
		}
		BFS();
		cout<<"Problem "<<testcase<<": ";
		cout<<costMap[mapSize-1][mapSize-1]<<endl;
		cin>>mapSize;
	}
	return 0;
}






