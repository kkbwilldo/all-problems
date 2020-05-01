#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX = 20;

int testcase,size;
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
int board[MAX][MAX];

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cout<<"#"<<test<<endl;
		memset(board,-1,sizeof(board));
		cin>>size;
		if(size==1){ // 여기 예외 처리 안해서 틀림 
			cout<<1<<endl;
			continue;
		}
		for(int r=1;r<=size;r++){
			for(int c=1;c<=size;c++){
				board[r][c]=0;
			}
		}
		int r,c,cnt,dir;
		r=c=cnt=1;dir=0;
		board[r][c]=cnt++;
		while(1){
			int nr=r+dr[dir];
			int nc=c+dc[dir];
			if(board[nr][nc]==-1) dir=(dir+1)%4; // 벽에 부딪히면 방향만 전환
			else if(board[nr][nc]>=1){ // 방문했던 곳이면 방향 전환
				dir=(dir+1)%4;
				if(board[r+dr[dir]][c+dc[dir]]>=1) break; // 방향 전환 후에도 방문한 곳일 때
			}
			else{ // 벽도 아니고 방문한 곳도 아니면 직진 
				r=nr;
				c=nc;
				board[r][c]=cnt++;
			}
		}
		for(int r=1;r<=size;r++){
			for(int c=1;c<=size;c++){
				cout<<board[r][c]<<" ";
			}cout<<endl;
		}
	}
	return 0;
}
