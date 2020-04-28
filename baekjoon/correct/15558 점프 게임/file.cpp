#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=100010;

int ROW,COL,jump;
int answer;
int dr[]={-1,1,-jump};
int dc[]={0,0,1};
int ladder[MAX][2];
bool gameClear;
bool visited[MAX][2];

void Play(){
	dr[2]=-jump;
	int StartR=ROW-1,StartC=0;
	queue <tuple<int,int,int> > q;
	q.push(make_tuple(StartR,StartC,0));
	visited[StartR][StartC]=true;
	while(!q.empty()){
		if(gameClear) break;
		int r,c,clk;
		tie(r,c,clk)=q.front();
		q.pop();
		for(int i=0;i<3;i++){
			int nr=r+dr[i];
			int nc=(c+dc[i])%2;
			if(nr<0){ // 게임 끝
				gameClear=true;
				break;
			}
			if(nr>=ROW) continue; // 갈 수 없는 곳
			if(ladder[nr][nc]==0) continue; // 위험한 곳 
			if(visited[nr][nc]) continue; // 방문했던 곳
			if(ROW-nr<=clk+1) continue; // 사라진 곳 	ㅇㅕ기서 틀림!!!!!!
			visited[nr][nc]=true;
			q.push(make_tuple(nr,nc,clk+1));
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>jump;
	COL=2;
	for(int c=0;c<COL;c++){
		string str;
		cin>>str;
		for(int r=ROW-1;r>=0;r--){
			ladder[r][c]=str[ROW-1-r]-'0';
		}
	}
	gameClear=false;
	Play();
	if(gameClear) answer++;
	cout<<answer<<endl;
	
	return 0;
}
