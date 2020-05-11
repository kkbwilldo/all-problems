#include <iostream>
#include <cstring>
using namespace std;

const int MAX=10;

int testcase,size,numPlays,numBlacks,numWhites;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};
int board[MAX][MAX];

void MarkUnit(int r,int c){
	int reference=board[r][c];
	for(int i=0;i<8;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		int cnt=0;
		while(1){
			if(nr<0||nr>=size||nc<0||nc>=size||board[nr][nc]==0){
				cnt=0;
				break;
			}
			if(board[nr][nc]==reference) break;
			cnt++;
			nr+=dr[i];
			nc+=dc[i];
		}
		for(int j=1;j<=cnt;j++){
			nr=r+dr[i]*j;
			nc=c+dc[i]*j;
			board[nr][nc]=reference;
		}
	}
}

void Init(){
	memset(board,0,sizeof(board));
	numBlacks=numWhites=0;
	board[size/2][size/2-1]=board[size/2-1][size/2]=1;
	board[size/2-1][size/2-1]=board[size/2][size/2]=2;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>numPlays;
		Init();
		for(int i=0;i<numPlays;i++){
			int r,c,unit,dir;
			cin>>c>>r>>unit;
			r--;c--;
			board[r][c]=unit;
			MarkUnit(r,c);
		}
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				if(board[r][c]==1) numBlacks++;
				else if(board[r][c]==2) numWhites++;
			}
		}
		cout<<"#"<<test<<" "<<numBlacks<<" "<<numWhites<<endl;
	}
	return 0;
}
