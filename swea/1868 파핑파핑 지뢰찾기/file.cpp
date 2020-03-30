#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

const int MAX = 300;
const int DIR = 8;

int testcase,mapSize;
int cnt,minCnt;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int result[MAX][MAX];
char map[MAX][MAX];
bool visited[MAX][MAX];
string str;

int numAround(int x,int y){
	cnt=0;
	for(int i=0;i<DIR;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||nx>=mapSize||ny<0||ny>=mapSize) continue;
		if(map[nx][ny]=='*') cnt++;
	}
	//result[x][y]=cnt;
	return cnt;
}

void bfs(int x,int y){
	visited[x][y]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		for(int i=0;i<DIR;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(nr<0||nr>=mapSize||nc<0||nc>=mapSize) continue;
			if(visited[nr][nc]) continue;
			if(numAround(nr,nc)==0){
				visited[nr][nc]=true;
				result[nr][nc]=0;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(map,0,sizeof(map));
		memset(result,-1,sizeof(result));
		memset(visited,0,sizeof(visited));
		cin>>mapSize;
		for(int i=0;i<mapSize;i++){
			cin>>str;
			for(int j=0;j<mapSize;j++){
				map[i][j]=str[j];
			}
		}
		for(int i=0;i<mapSize;i++){
			for(int j=0;j<mapSize;j++){
				if(map[i][j]=='.'){
					if(result[i][j]==-1){
						if(numAround(i,j)==0){
							result[i][j]=0;
							minCnt++;
							bfs(i,j);
						}
					}
				}
			}
		}
		for(int i=0;i<mapSize;i++){
			for(int j=0;j<mapSize;j++){
				if(result[i][j]==-1){
					result[i][j]=numAround(i,j);
					minCnt++;
				}
			}
		}
		cout<<"#"<<test<<" "<<minCnt<<endl;
	}
	
	return 0;
}

