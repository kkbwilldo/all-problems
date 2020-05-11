#include <iostream>
#include <cstring>
using namespace std;

const int ROW=300;
const int MAX=1010;

int answer,COL;
int dc[]={-2,-1,1,2};
int heights[MAX];  // char 타입 쓰면 틀린다!!!!!!!!!!!
int board[ROW][MAX];

void SetBoard(){
	for(int c=0;c<COL;c++){
		if(heights[c]==0) continue;
		for(int r=ROW-1;r>=ROW-heights[c];r--) board[r][c]=1;
	}
}

void CheckView(){
	for(int c=0;c<COL;c++){
		for(int r=ROW-1;r>=0;r--){
			if(board[r][c]==0) break;
			int cnt=0;
			for(int i=0;i<4;i++){
				int nc=c+dc[i];
				if(nc<0||nc>=COL) break;
				if(board[r][nc]==1) break;
				cnt++;
			}
			if(cnt==4) answer++;
		}
	}
}


int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int test=1;test<=10;test++){
		memset(board,0,sizeof(board));
		memset(heights,0,sizeof(heights));
		answer=0;
		cin>>COL;
		for(int c=0;c<COL;c++) cin>>heights[c];
		SetBoard();
		CheckView();
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
