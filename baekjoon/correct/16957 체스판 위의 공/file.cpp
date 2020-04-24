#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX=505;

int ROW,COL;
int minVal;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};
int board[MAX][MAX],score[MAX][MAX];
vector <pair<int,int> > dp[MAX][MAX];

void Move(int r,int c){
	queue <pair<int,int> > q;
	q.push(make_pair(r,c));
	while(1){
		minVal=board[r][c];
		int nextR,nextC;
		for(int i=0;i<8;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(minVal>board[nr][nc]){
				minVal=board[nr][nc];
				nextR=nr;
				nextC=nc;
			}
		}
		if(minVal==board[r][c]) break;
		if(dp[nextR][nextC].size()>0){
			r=dp[nextR][nextC][0].first;
			c=dp[nextR][nextC][0].second;
			break;
		}
		q.push(make_pair(nextR,nextC));
		r=nextR;
		c=nextC;
	}
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		dp[x][y].push_back(make_pair(r,c));
	}
	score[r][c]++;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
		}
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			Move(r,c);
		}
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<score[r][c]<<" ";
		}cout<<endl;
	}
	return 0;
}
