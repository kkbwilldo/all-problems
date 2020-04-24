#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=20;
const int INF=987987987;

int testcase;
int numBombs,ROW,COL;
int minVal;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int bombCol[MAX];
int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX];

void PullDown(){ // ㅇㅣ 부분 다시 공부하자!!!!!!!!!!!!!
	for(int c=0;c<COL;c++){
		for(int r=ROW-2;r>=0;r--){
			if(board[r][c]==0) continue;
			int nr=r+1;
			while(nr<ROW){
				if(board[nr][c]!=0) break;
				nr++;
			}
			nr--;
			if(nr==r) continue; // ㅇㅕ기 틀림
			board[nr][c]=board[r][c];
			board[r][c]=0;
		}
	}
}

void DropBombs(int r,int c){
	visited[r][c]=true;
	int size=board[r][c];//ㅇㅕ기 틀림
	board[r][c]=0;
	for(int i=0;i<4;i++){
		int nr=r;
		int nc=c;
		for(int j=1;j<size;j++){//ㅇㅕ기 틀림
			nr+=dr[i];
			nc+=dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) break;
			if(board[nr][nc]==0) continue;
			if(visited[nr][nc]) continue;
			DropBombs(nr,nc);			
		}
	}
}

int CheckNumBlocks(){
	int cnt=0;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(board[r][c]!=0) cnt++;
		}
	}
	return cnt;
}

void InitBoard(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			board[r][c]=temp[r][c];
		}
	}
}

int FindRow(int c){
	for(int r=0;r<ROW;r++){
		if(board[r][c]!=0) return r;
	}
	return -1;
}

void Print(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<board[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void GetBombCol(int depth){
	if(depth==numBombs){
		InitBoard();
		for(int i=0;i<numBombs;i++){
			int c=bombCol[i];
			int r=FindRow(c);
			if(r==-1) continue;  // return ㅎㅏ면 틀린다 
			memset(visited,0,sizeof(visited));
			DropBombs(r,c);
			PullDown();
		}
		int result=CheckNumBlocks();
		minVal=min(minVal,result);
		return;
	}
	for(int i=0;i<COL;i++){
		bombCol[depth]=i;
		GetBombCol(depth+1);
	}
}

void Test(){
	bombCol[0]=2;bombCol[1]=2;bombCol[2]=6;
	for(int i=0;i<3;i++){
		int c=bombCol[i];
		int r=FindRow(c);
		memset(visited,0,sizeof(visited));
		DropBombs(r,c);
		PullDown();
	}
	cout<<CheckNumBlocks()<<endl;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numBombs>>COL>>ROW;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>board[r][c];
				temp[r][c]=board[r][c];
			}
		}
		minVal=INF;
		GetBombCol(0);
		//Test();
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
