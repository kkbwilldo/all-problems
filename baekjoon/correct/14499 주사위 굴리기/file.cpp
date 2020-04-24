#include <iostream>
#define endl '\n'
using namespace std;

int ROW,COL;
int R,C,numCmds,dir;
int dice[7];
int dr[]={0,0,0,-1,1};
int dc[]={0,1,-1,0,0};
int board[25][25];

bool Roll(int r,int c,int dir){
	int nr=r+dr[dir];
	int nc=c+dc[dir];
	if(nr<0||nr>=ROW||nc<0||nc>=COL) return false;
	R=nr;
	C=nc;
	int temp=dice[1];
	if(dir==1){
		dice[1]=dice[4];
		dice[4]=dice[6];
		dice[6]=dice[3];
		dice[3]=temp;
	}
	else if(dir==2){
		dice[1]=dice[3];
		dice[3]=dice[6];
		dice[6]=dice[4];
		dice[4]=temp;
	}
	else if(dir==3){
		dice[1]=dice[5];
		dice[5]=dice[6];
		dice[6]=dice[2];
		dice[2]=temp;
	}
	else if(dir==4){
		dice[1]=dice[2];
		dice[2]=dice[6];
		dice[6]=dice[5];
		dice[5]=temp;
	}
	if(board[nr][nc]==0) board[nr][nc]=dice[6];
	else{
		dice[6]=board[nr][nc];
		board[nr][nc]=0;
	}
	return true;
}

void Print(){
	cout<<dice[1]<<endl;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>R>>C>>numCmds;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
		}
	}
	for(int i=0;i<numCmds;i++){
		cin>>dir;
		if(Roll(R,C,dir))
			Print();
	}
	return 0;
}
