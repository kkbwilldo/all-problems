#include <iostream>
#include <cstring>
using namespace std;

const int MAX=350;

int ROW,COL,answer;
int DP[MAX][MAX]; // 크기가 NxM인 초콜릿을 자르는 최소 횟수

int dfs(int r,int c){
	if(DP[r][c]!=-1) return DP[r][c];
	if(r>c){
		if(r%2==0){
			DP[r][c]=DP[c][r]=dfs(r/2,c)+dfs(r/2,c)+1;
			return DP[r][c];
		}
		else{
			DP[r][c]=DP[c][r]=dfs(r/2,c)+dfs(r/2+1,c)+1;
			return DP[r][c];
		}
	}
	else{
		if(c%2==0){
			DP[r][c]=DP[c][r]=dfs(r,c/2)+dfs(r,c/2)+1;
			return DP[r][c];
		}
		else{
			DP[r][c]=DP[c][r]=dfs(r,c/2)+dfs(r,c/2+1)+1;
			return DP[r][c];
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	memset(DP,-1,sizeof(DP));
	DP[1][1]=0;
	cin>>ROW>>COL;
	answer=dfs(ROW,COL);
	cout<<answer<<endl;
	return 0;
}
