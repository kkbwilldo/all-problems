#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=14;

int testcase;
int ROW,COL,StartR,StartC;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];

string answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		answer="";
		cin>>ROW>>COL;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>board[r][c];
				if(board[r][c]=='O'){
					StartR=r;
					StartC=c;
				}
			}
		}
		
		
		
		
		
		
		
	}
	return 0;
}

