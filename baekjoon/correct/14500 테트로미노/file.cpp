#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX=510;

int ROW,COL,maxVal;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int fourMoreR[][4]={{0,0,0,-1},{0,0,0,1},{0,1,2,1},{0,1,2,1}};
int fourMoreC[][4]={{0,1,2,1},{0,1,2,1},{0,0,0,1},{0,0,0,-1}};
int Map[MAX][MAX];
bool visited[MAX][MAX];

void Spread(int r,int c,int depth,int sum){
	if(depth==4){
		maxVal=max(maxVal,sum);
		return;
	}
	for(int i=0;i<4;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
		if(visited[nr][nc]) continue;
		visited[nr][nc]=true;
		Spread(nr,nc,depth+1,sum+Map[r][c]);
		visited[nr][nc]=false;
	}
}

void FourCases(int r,int c){
	for(int i=0;i<4;i++){
		int cnt=0;
		bool outBorder=false;
		for(int j=0;j<4;j++){
			int nr=r+fourMoreR[i][j];
			int nc=c+fourMoreC[i][j];
			if(nr<0||nr>=ROW||nc<0||nc>=COL){
				outBorder=true;
				break;
			}
			cnt+=Map[nr][nc];
		}
		if(!outBorder) maxVal=max(maxVal,cnt);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>Map[r][c];
		}
	}
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			visited[r][c]=true;
			Spread(r,c,0,0);
			visited[r][c]=false;
			FourCases(r,c);
		}
	}
	cout<<maxVal<<endl;
	return 0;
}
