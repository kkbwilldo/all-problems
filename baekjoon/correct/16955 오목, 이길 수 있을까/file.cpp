#include <iostream>
#include <string>
using namespace std;

const int MAX=10;
const int OMOK=4;

char board[MAX][MAX];
int answer;
int dr[]={0,1,1,1};
int dc[]={1,0,1,-1};
string str;

bool Check(){
	for(int r=0;r<MAX;r++){
		for(int c=0;c<MAX;c++){
			if(board[r][c]!='X') continue;
			for(int i=0;i<4;i++){
				int cnt=0;
				int nr=r;
				int nc=c;
				for(int j=0;j<OMOK;j++){
					nr+=dr[i];
					nc+=dc[i];
					if(nr<0||nr>=MAX||nc<0||nc>=MAX) break;
					if(board[nr][nc]!='X') break;
					cnt++;
				}
				if(cnt==OMOK) return true;
			}
		}
	}
	return false;
}

void AllCases(){
	if(Check()){
		answer=1;
		return;
	}
	for(int r=0;r<MAX;r++){
		for(int c=0;c<MAX;c++){
			if(board[r][c]!='.') continue;
			board[r][c]='X';
			if(Check()){
				answer=1;
				return;
			}
			board[r][c]='.';
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int r=0;r<MAX;r++){
		cin>>str;
		for(int c=0;c<MAX;c++){
			board[r][c]=str[c];
		}
	}
	AllCases();
	cout<<answer<<endl;
	return 0;
}
