#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int INF = 987987987;
const int SIZE = 100;

int minVal,idx;
int A,B;
int numUsers,numRelations;
int board[SIZE+5][SIZE+5];

void FloydWarShall(){
	for(int Mid=1;Mid<=numUsers;Mid++){
		for(int Start=1;Start<=numUsers;Start++){
			for(int End=1;End<=numUsers;End++){
				if(Start==End) continue;
				if(board[Start][Mid]!=0&&board[Mid][End]!=0){
					if(board[Start][End]==0) board[Start][End]=board[Start][Mid]+board[Mid][End];
					else board[Start][End] = min(board[Start][End],board[Start][Mid]+board[Mid][End]);
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
	
	cin>>numUsers>>numRelations;
	for(int i=0;i<numRelations;i++){
		cin>>A>>B;
		board[A][B]=1;
		board[B][A]=1;
	}
	
	FloydWarShall();
	
	minVal=INF;
	for(int i=1;i<=numUsers;i++){
		int Kevin=0;
		for(int j=1;j<=numUsers;j++){
			Kevin+=board[i][j];
		}
		if(minVal>Kevin){
			idx=i;
			minVal=Kevin;
		}
	}
	cout<<idx<<endl;
	return 0;
}
