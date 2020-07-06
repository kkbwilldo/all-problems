#include <iostream>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=1010;

int ROW,COL,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX];

queue <pair<int,int> > q;

void Check(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(board[r][c]==0&&!visited[r][c]){
				answer=-1;
				return;
			}
		}
	}
}

void Print(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<visited[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>COL>>ROW;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
			if(board[r][c]==1){
				q.push(make_pair(r,c));
				visited[r][c]=true;
			}
		}
	}
	
	while(!q.empty()){	
		bool flag=false;
		int size=q.size();
		for(int i=0;i<size;i++){
			int r=q.front().first;
			int c=q.front().second;
			q.pop();
			for(int j=0;j<4;j++){
				int nr=r+dr[j];
				int nc=c+dc[j];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
				if(board[nr][nc]!=0) continue;
				if(visited[nr][nc]) continue;
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
				flag=true;
			}
		}
		if(flag) answer++;
	}

	Check();
	cout<<answer<<endl;
	return 0;
}
