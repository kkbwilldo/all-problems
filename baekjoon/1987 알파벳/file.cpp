#include <iostream>
#include <unordered_set>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX=30;

int ROW,COL,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
unordered_set <char> check;

void DFS(int r,int c,int cnt){
	answer=max(answer,cnt);
	char letter=board[r][c];
	for(int i=0;i<4;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
		char Next=board[nr][nc];
		if(check.find(Next)!=check.end()) continue;
		check.insert(Next);
		DFS(nr,nc,cnt+1);
		check.erase(Next);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int StartR=0;
	int StartC=0;
	
	cin>>ROW>>COL;
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
		}
	}
	check.insert(board[StartR][StartC]);
	DFS(StartR,StartC,1);
	cout<<answer<<endl;
	return 0;
}
