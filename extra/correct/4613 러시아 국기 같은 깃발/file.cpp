#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=60;
const int INF=987987987;

char board[MAX][MAX];
int testcase,minVal;
int ROW,COL;

void CheckDifference(int w,int b,int r){
	int cnt=0;
	for(int x=0;x<=b-1;x++){ // 여기서 x<=b-1 대신 x<=w 라고 해서 틀림!!!!
		for(int c=0;c<COL;c++){
			if(board[x][c]!='W') cnt++;
		}
	}
	for(int x=b;x<=r-1;x++){
		for(int c=0;c<COL;c++){
			if(board[x][c]!='B') cnt++;
		}
	}
	for(int x=r;x<=ROW-1;x++){
		for(int c=0;c<COL;c++){
			if(board[x][c]!='R') cnt++;
		}
	}
	minVal=min(minVal,cnt);
}

void AllCases(){
	for(int w=0;w<=ROW-3;w++){
		for(int b=w+1;b<=ROW-2;b++){
			for(int r=b+1;r<=ROW-1;r++){
				CheckDifference(w,b,r);
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		minVal=INF;
		cin>>ROW>>COL;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>board[r][c];
			}
		}
		AllCases();
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
