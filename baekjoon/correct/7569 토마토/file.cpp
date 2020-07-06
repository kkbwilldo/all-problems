#include <iostream>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=110;

int ROW,COL,HEIGHT,answer;
int dr[]={-1,1,0,0,0,0};
int dc[]={0,0,-1,1,0,0};
int dh[]={0,0,0,0,-1,1};
int board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

queue <tuple<int,int,int> > q;

void Check(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			for(int h=0;h<HEIGHT;h++){
				if(board[r][c][h]==0&&!visited[r][c][h]){
					answer=-1;
					return;
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>COL>>ROW>>HEIGHT;
	for(int h=0;h<HEIGHT;h++){
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>board[r][c][h];
				if(board[r][c][h]==1){
					q.push(make_tuple(r,c,h));
					visited[r][c][h]=true;
				}
			}
		}
	}
	
	while(!q.empty()){
		bool flag=false;
		int size=q.size();
		for(int i=0;i<size;i++){
			int r,c,h;
			tie(r,c,h)=q.front();
			q.pop();
			for(int j=0;j<6;j++){
				int nr=r+dr[j];
				int nc=c+dc[j];
				int nh=h+dh[j];
				if(nr<0||nr>=ROW||nc<0||nc>=COL||nh<0||nh>=HEIGHT) continue;
				if(board[nr][nc][nh]!=0) continue;
				if(visited[nr][nc][nh]) continue;
				visited[nr][nc][nh]=true;
				q.push(make_tuple(nr,nc,nh));
				flag=true;
			}
		}
		if(flag) answer++;
	}
	
	Check();
	
	cout<<answer<<endl;
	return 0;
}
