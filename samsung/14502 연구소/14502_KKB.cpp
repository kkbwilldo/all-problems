/*
3개의 벽을 놓을 수 있는 모든 경우의 수 탐색
putWall() 함수로 중복되지 않게 3개의 벽을 고른다
3개의 벽이 놓이면
Spread() 함수로 모든 바이러스를 퍼트린다
모든 바이러스가 퍼지면
SafeZone() 함수로 안전지역의 개수를 센다
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX = 10;

int ROW,COL,maxVal;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

vector <pair<int,int> > OpenSpace;
vector <pair<int,int> > Virus;

void Spread(){
	memset(visited,0,sizeof(visited));
	memset(temp,0,sizeof(temp));
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			temp[r][c]=map[r][c];
		}
	}
	for(int virus=0;virus<Virus.size();virus++){
		int x=Virus[virus].first;
		int y=Virus[virus].second;
		visited[x][y]=true;
		queue <pair<int,int> > q;
		q.push(make_pair(x,y));
		while(!q.empty()){
			int r=q.front().first;
			int c=q.front().second;
			temp[r][c]=2;
			q.pop();
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
				if(visited[nr][nc]) continue;
				if(temp[nr][nc]!=0) continue;
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

int SafeZone(){
	int cnt=0;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(temp[r][c]==0){
				cnt++;
			}
		}
	}
	return cnt;
}

void putWall(int StartIdx,int numWalls){
	if(numWalls==3){
		Spread();
		int numSafe=SafeZone();
		maxVal=max(maxVal,numSafe);
		return;
	}
	for(int i=StartIdx;i<OpenSpace.size();i++){
		int r=OpenSpace[i].first;
		int c=OpenSpace[i].second;
		map[r][c]=1;
		putWall(i+1,numWalls+1);
		map[r][c]=0;
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
			if(map[r][c]==0) OpenSpace.push_back(make_pair(r,c));
			else if(map[r][c]==2) Virus.push_back(make_pair(r,c));
		}
	}
	putWall(0,0);
	cout<<maxVal<<endl;
	return 0;
}
