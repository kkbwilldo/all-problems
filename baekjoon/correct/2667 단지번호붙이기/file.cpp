#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=30;

int size;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
bool visited[MAX][MAX];

vector <int> answer;

void bfs(int StartR,int StartC){
	int cnt=0;
	visited[StartR][StartC]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(StartR,StartC));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		cnt++;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(board[nr][nc]=='0') continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_pair(nr,nc));
		}
	}
	answer.push_back(cnt);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>board[r][c];
		}
	}
	
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(board[r][c]=='1'&&!visited[r][c]){
				bfs(r,c);
			}
		}
	}
	
	cout<<answer.size()<<endl;
	sort(answer.begin(),answer.end());
	for(int i=0;i<answer.size();i++) cout<<answer[i]<<endl;
	return 0;
}
