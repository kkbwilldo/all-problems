#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX = 501;

int ROW,COL;
int cnt;
char map[MAX][MAX];
bool isPossible;
bool visited[MAX][MAX], possible[MAX][MAX];

bool Search(int startR,int startC){
	memset(visited,0,sizeof(visited));
	visited[startR][startC]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(startR,startC));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		char dir=map[r][c];
		int nr=r;
		int nc=c;
		if(dir=='U') nr-=1;
		else if(dir=='D') nr+=1;
		else if(dir=='L') nc-=1;
		else if(dir=='R') nc+=1;
		if(nr<0||nr>=ROW||nc<0||nc>=COL) return true;
		if(visited[nr][nc]) continue;
		visited[nr][nc]=true;
		q.push(make_pair(nr,nc));
	}
	return false;
}

void Check(int r,int c){
	int nr=r;
	int nc=c;
	while(0<=nr&&nr<ROW&&0<=nc&&nc<COL){
		possible[nr][nc]=true;
		char dir=map[nr][nc];
		if(dir=='U') nr-=1;
		else if(dir=='D') nr+=1;
		else if(dir=='L') nc-=1;
		else if(dir=='R') nc+=1;
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
		}
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(possible[r][c]) continue;
			isPossible=Search(r,c);
			if(isPossible) Check(r,c);
		}
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(possible[r][c]) cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
