#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

const int MAX = 8;

int testcase,size,dig;
int maxVal;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int map[MAX][MAX];
bool visited[MAX][MAX];
bool hasDigged;

void dfs(int x,int y,int cnt){
	if(maxVal<cnt) maxVal=cnt;
	for(int dir=0;dir<4;dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(nx<0||nx>=size||ny<0||ny>=size) continue;
		if(!visited[nx][ny]){
			if(map[x][y]>map[nx][ny]){
				visited[nx][ny] = true;
				dfs(nx,ny,cnt+1);
				visited[nx][ny] = false;
			}
			else{
				if(!hasDigged && map[x][y]>map[nx][ny]-dig){
					hasDigged = visited[nx][ny] = true;
					int next = map[nx][ny];
					map[nx][ny] = map[x][y]-1;
					dfs(nx,ny,cnt+1);
					map[nx][ny] = next;
					hasDigged = visited[nx][ny] = false;
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>dig;
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		maxVal = 0;
		vector <pair<int,int> > peaks;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cin>>map[i][j];
				if(maxVal<map[i][j]){
					maxVal = map[i][j];
					peaks.clear();
					peaks.push_back(make_pair(i,j));
				}
				else if(maxVal==map[i][j]){
					peaks.push_back(make_pair(i,j));
				}
			}
		}
		maxVal = 0;
		for(int i=0;i<peaks.size();i++){
			int x = peaks[i].first;
			int y = peaks[i].second;
			visited[x][y] = true;
			dfs(x,y,1);
			visited[x][y] = false;
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}


