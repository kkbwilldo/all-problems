#include <iostream>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=25;
const int LIMIT=10;

int ROW,COL,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];

struct Coin{
	int r,c;
	Coin():r(-1),c(-1){}
	Coin(int _r,int _c):r(_r),c(_c){}
};

Coin coin[2];

void BFS(){
	queue <tuple<Coin,Coin,int> > q;
	q.push(make_tuple(coin[0],coin[1],0)); // <coin1,coin2,cnt>
	while(!q.empty()){
		Coin coin1,coin2;
		int cnt;
		tie(coin1,coin2,cnt)=q.front();
		q.pop();
		if(cnt>=LIMIT) continue; // cnt는 현재까지 버튼 누른 횟수
		// 다음 위치 찾기
		for(int i=0;i<4;i++){
			int nr1=coin1.r+dr[i];
			int nc1=coin1.c+dc[i];
			int nr2=coin2.r+dr[i];
			int nc2=coin2.c+dc[i];
			int ncnt=cnt+1;
			int numFalls=0;
			if(nr1<0||nr1>=ROW||nc1<0||nc1>=COL){
				numFalls++;
			}
			if(nr2<0||nr2>=ROW||nc2<0||nc2>=COL){
				numFalls++;
			}
			if(numFalls>1) continue;
			else if(numFalls==1){
				answer=ncnt;
				return;
			}
			if(board[nr1][nc1]=='#'&&board[nr2][nc2]=='#') continue;
			else if(board[nr1][nc1]=='#'){
				nr1=coin1.r;
				nc1=coin1.c;
			}
			else if(board[nr2][nc2]=='#'){
				nr2=coin2.r;
				nc2=coin2.c;
			}
			q.push(make_tuple(Coin(nr1,nc1),Coin(nr2,nc2),ncnt));
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	int idx=0;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
			if(board[r][c]=='o'){
				coin[idx++]=Coin(r,c);
			}
		}
	}
	
	answer=-1;
	BFS();
	cout<<answer<<endl;
	
	return 0;
}
