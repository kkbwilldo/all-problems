#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=100;
const int TESTCASE=10;
int maxVal,sum;
int board[MAX][MAX];

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
		
	for(int i=0;i<TESTCASE;i++){
		memset(board,0,sizeof(board));
		maxVal=0;
		int test;
		cin>>test;
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				cin>>board[r][c];
			}
		}
		for(int r=0;r<MAX;r++){
			sum=0;
			for(int c=0;c<MAX;c++){
				sum+=board[r][c];
			}
			maxVal=max(maxVal,sum);
		}
		for(int c=0;c<MAX;c++){
			sum=0;
			for(int r=0;r<MAX;r++){
				sum+=board[r][c];
			}
			maxVal=max(maxVal,sum);
		}
		
		sum=board[0][0];
		for(int i=1;i<MAX;i++) sum+=board[i][i];
		maxVal=max(maxVal,sum);
		sum=board[0][MAX-1];
		for(int i=1;i<MAX;i++) sum+=board[i][MAX-1-i];
		maxVal=max(maxVal,sum);
		
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
