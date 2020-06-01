#include <iostream>
using namespace std;

const int MAX=55;

int ROW,COL,cnt;
int board[MAX][MAX],answer[MAX][MAX];

void Flip(int r,int c){
	for(int i=r;i<r+3;i++){
		for(int j=c;j<c+3;j++){
			board[i][j]=!board[i][j];
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			char temp;
			cin>>temp;
			board[r][c]=temp-'0';
		}
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			char temp;
			cin>>temp;
			answer[r][c]=temp-'0';
		}
	}
	for(int r=0;r<ROW-2;r++){
		for(int c=0;c<COL-2;c++){
			if(board[r][c]!=answer[r][c]){
				Flip(r,c);
				cnt++;
			}
		}
	}
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(board[r][c]!=answer[r][c]){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
