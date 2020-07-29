#include <iostream>
#include <string>
#define ll long long
#define endl '\n'
using namespace std;

const int MAX=110;

ll size,answer;
int dr[]={1,0};
int dc[]={0,1};
int board[MAX][MAX];
ll DP[MAX][MAX];

// 점프가 0인 부분 확인
ll DFS(int r,int c){
	if(r==size-1&&c==size-1){
		return 1;
	}
	if(board[r][c]==0){
		return 0;
	}
	if(DP[r][c]!=0) return DP[r][c];
	int jump=board[r][c];
	for(int i=0;i<2;i++){
		int nr=r+dr[i]*jump;
		int nc=c+dc[i]*jump;
		if(nr<0||nr>=size||nc<0||nc>=size) continue;
		DP[r][c]+=DFS(nr,nc);
	}
	return DP[r][c];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("input.txt","r",stdin);

	cin>>size;

	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>board[r][c];
		}
	}

	answer=DFS(0,0);
	cout<<answer<<endl;

	return 0;
}
