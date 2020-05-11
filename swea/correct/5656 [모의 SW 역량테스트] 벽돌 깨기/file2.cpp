// 벽돌 깨기 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int MAX=20;
const int INF=987987987;

int testcase;
int minVal;
int numDrops,ROW,COL;
int locations[MAX];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX],originals[MAX][MAX];

void Copy(int board[][MAX],int originals[][MAX]){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			board[r][c]=originals[r][c];
		}
	}
}

int GetRow(int c){
	int R=ROW-1;
	for(int r=0;r<ROW;r++){
		if(board[r][c]) return r;
	}
	return R;
}

void Explode(int StartR,int StartC){
	int len=board[StartR][StartC];
	if(len==0) return;
	board[StartR][StartC]=0;
	queue <tuple<int,int,int> > q;
	q.push(make_tuple(StartR,StartC,len));
	while(!q.empty()){
		int r,c,range;
		tie(r,c,range)=q.front();
		q.pop();
		if(range<=1) continue;
		for(int i=0;i<4;i++){
			int nr=r;
			int nc=c;
			for(int j=2;j<=range;j++){
				nr+=dr[i];
				nc+=dc[i];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) break;
				if(board[nr][nc]==0) continue;
				q.push(make_tuple(nr,nc,board[nr][nc]));
				board[nr][nc]=0;
			}
		}
	}
}

void PullDown(){
	for(int r=ROW-1;r>=1;r--){
		for(int c=0;c<COL;c++){
			if(board[r][c]) continue;
			int nr=r-1;
			while(nr>=0){
				if(board[nr][c]){
					board[r][c]=board[nr][c];
					board[nr][c]=0;
					break;
				}
				nr--;
			}
		}
	}
}

int GetNumBricks(){
	int numBricks=0;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(board[r][c]) numBricks++;
		}
	}
	return numBricks;
}

void AllCases(int depth){
	if(depth==numDrops){
		Copy(board,originals);
		for(int i=0;i<numDrops;i++){
			int StartC=locations[i];
			int StartR=GetRow(StartC);
			Explode(StartR,StartC);
			PullDown();
		}
		minVal=min(minVal,GetNumBricks());
		return;
	}
	for(int c=0;c<COL;c++){
		locations[depth]=c;
		AllCases(depth+1);
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		memset(originals,0,sizeof(originals));
		minVal=INF;
		cin>>numDrops>>COL>>ROW;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>originals[r][c];
			}
		}
		AllCases(0);
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
