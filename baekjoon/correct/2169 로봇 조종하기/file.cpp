#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1010;

int ROW,COL;
int map[MAX][MAX];
int DP[MAX][MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			cin>>map[i][j];
		}
	}
	DP[0][0]=map[0][0];
	for(int c = 1;c<COL;c++) DP[0][c] = DP[0][c-1]+map[0][c];
	for(int r=1;r<ROW;r++){
		int row[COL][2];
		for(int c=0;c<COL;c++){
			if(c-1<0) row[c][0]=DP[r-1][c]+map[r][c];
			else row[c][0]=map[r][c]+max(DP[r-1][c],row[c-1][0]);
		}
		for(int c=COL-1;c>=0;c--){
			if(c+1>=COL) row[c][1]=DP[r-1][c]+map[r][c];
			else row[c][1]=map[r][c]+max(DP[r-1][c],row[c+1][1]);
		}
		for(int c=0;c<COL;c++) DP[r][c]=max(row[c][0],row[c][1]);
	}
	
	cout<<DP[ROW-1][COL-1]<<endl;
	return 0;
}
