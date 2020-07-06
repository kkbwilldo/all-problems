#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=1010;

int testcase,size,answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char answerBoard[MAX][MAX];
char playBoard[MAX][MAX];

void Init(){
	memset(answerBoard,0,sizeof(answerBoard));
	answer=0;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			playBoard[r][c]='W';
		}
	}
}

void Flip(int r,int c){
	for(int h=0;h<4;h++){
		int nr=r+dr[h];
		int nc=c+dc[h];
		while(0<=nr&&nr<size&&0<=nc&&nc<size){
			if(playBoard[nr][nc]=='B') playBoard[nr][nc]='W';
			else playBoard[nr][nc]='B';
			nr+=dr[h];
			nc+=dc[h];
		}
	}
}

bool CheckDone(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(answerBoard[r][c]!=playBoard[r][c]) return false;
		}
	}
	return true;
}

void 

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size;
		Init();
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>answerBoard[r][c];
			}
		}
		
	}
	return 0;
}
