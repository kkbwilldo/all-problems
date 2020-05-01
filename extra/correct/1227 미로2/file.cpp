#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

const int MAX=100;

int test,StartR,StartC,EndR,EndC;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX];

void Search(int x,int y){
	memset(visited,0,sizeof(visited));
	visited[x][y]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		if(r==EndR&&c==EndC) return;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=MAX||nc<0||nc>=MAX) continue;
			if(board[nr][nc]==1) continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_pair(nr,nc));
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<10;i++){
		cin>>test;
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				char temp;
				cin>>temp;
				board[r][c]=temp-'0';
				if(board[r][c]==2){
					StartR=r;
					StartC=c;
				}
				else if(board[r][c]==3){
					EndR=r;
					EndC=c;
				}
			}
		}
		Search(StartR,StartC);
		cout<<"#"<<test<<" ";
		if(visited[EndR][EndC]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
