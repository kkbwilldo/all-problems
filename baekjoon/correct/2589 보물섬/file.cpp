/*
전체 탐색으로 모든 칸을 시작점으로 하여, 각 시작점으로부터
이동할 수 있는 육지를 모두 탐색하며 갈 수 있는 최대 거리값을
매번 구한다.
그 중 최대값을 출력한다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;

const int MAX = 60;

int row,col;
int maxVal;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char map[MAX][MAX];
bool visited[MAX][MAX];
string str;

void bfs(int x,int y){
	memset(visited,0,sizeof(visited));
	queue <pair<pair<int,int>,int > > q;
	visited[x][y]=true;
	q.push(make_pair(make_pair(x,y),0));
	while(!q.empty()){
		int r=q.front().first.first;
		int c=q.front().first.second;
		int dist=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			int ndist=dist+1;
			if(nr<0||nr>=row||nc<0||nc>=col) continue;
			if(map[nr][nc]=='L'&&!visited[nr][nc]){
				visited[nr][nc]=true;
				maxVal=max(maxVal,ndist);
				q.push(make_pair(make_pair(nr,nc),ndist));
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>row>>col;
	for(int i=0;i<row;i++){
		cin>>str;
		for(int j=0;j<col;j++){
			map[i][j]=str[j];
		}
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(map[i][j]=='L') bfs(i,j);
		}
	}
	cout<<maxVal<<endl;
	return 0;
}

