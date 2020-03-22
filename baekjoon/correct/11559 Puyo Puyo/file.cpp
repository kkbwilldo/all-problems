/*
CheckAndPop(), PullDown()으로 모듈화하여 문제 해결
CheckAndPop() 함수는 bfs()를 이용하여 4개 이상 연속된 블록이 있는지 찾는다
찾는 방법은 연속된 블록 모두를 벡터 pos에 좌표를 저장하여 마지막에 pos의 크기가 4이상인지 확인
4미만이면 pos의 좌표 모두 방문 취소 처리를 하고
4이상이면 모든 좌표를 '.'으로 만든다
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#define endl '\n'
#define ROW 12
#define COL 6
using namespace std;

char map[ROW][COL];
int numChains;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
bool isPop;
bool visited[ROW][COL];
string str;

void bfs(int x,int y){
	visited[x][y]=true;
	vector <pair<int,int> > pos;
	queue <pair<int,int> > q;
	pos.push_back(make_pair(x,y));
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		char idx = map[r][c];
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc]) continue;
			if(map[nr][nc]==idx){
				visited[nr][nc]=true;
				pos.push_back(make_pair(nr,nc));
				q.push(make_pair(nr,nc));
			}
		}
	}
	if(pos.size()>=4){
		for(int i=0;i<pos.size();i++){
			int r=pos[i].first;
			int c=pos[i].second;
			map[r][c]='.';
		}
		isPop=true;
	}
	else{
		for(int i=0;i<pos.size();i++){
			int r=pos[i].first;
			int c=pos[i].second;
			visited[r][c]=false;
		}
	}
}

void CheckAndPop(){
	isPop=false;
	memset(visited,0,sizeof(visited));
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(visited[r][c]) continue;
			if(map[r][c]=='.') continue;
			bfs(r,c);
		}
	}
}

void PullDown(){
	for(int r=ROW-2;r>=0;r--){
		for(int c=0;c<COL;c++){
			if(map[r+1][c]!='.') continue;
			int temp=r;
			while(temp<ROW-1&&map[temp+1][c]=='.'){
				map[temp+1][c]=map[temp][c];
				map[temp][c]='.';
				temp++;
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int r=0;r<ROW;r++){
		cin>>str;
		for(int c=0;c<COL;c++){
			map[r][c]=str[c];
		}
	}
	
	CheckAndPop();
	while(isPop){
		numChains++;
		PullDown();
		CheckAndPop();
	}
	
	cout<<numChains<<endl;
	return 0;
}



