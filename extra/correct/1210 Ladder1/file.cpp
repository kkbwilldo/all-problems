#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX=100;

int testcase,answer;
int dr[]={0,0,-1};
int dc[]={-1,1,0};
int board[MAX][MAX];
bool visited[MAX][MAX];

void WrongWayDrive(int col){
	queue <pair<int,int> > q;
	int StartR=MAX-1;
	int StartC=col;
	visited[StartR][StartC]=true;
	q.push(make_pair(StartR,StartC));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		if(r==0){
			answer=c;
			break;
		}
		for(int i=0;i<3;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=MAX||nc<0||nc>=MAX) continue;
			if(visited[nr][nc]) continue;
			if(board[nr][nc]==1){
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
				break;
			}
		}
	}	
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<10;i++){
		memset(board,0,sizeof(board));
		memset(visited,0,sizeof(visited));
		int StartC;
		cin>>testcase;
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				cin>>board[r][c];
				if(board[r][c]==2) StartC=c;
			}
		}
		WrongWayDrive(StartC);
		cout<<"#"<<testcase<<" "<<answer<<endl;
	}
	return 0;
}
