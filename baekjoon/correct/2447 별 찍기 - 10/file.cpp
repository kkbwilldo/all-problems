#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=27*27*9;
int size;
char board[MAX][MAX];

void Init(){
	for(int r=0;r<MAX;r++){
		for(int c=0;c<MAX;c++){
			board[r][c]=' ';
		}
	}
}

void Recurse(int size,int StartR,int StartC){
	if(size==1){
		board[StartR][StartC]='*';
		return;
	}
	int NextSize=size/3;
	for(int r=0;r<3;r++){
		for(int c=0;c<3;c++){
			if(r==1&&c==1) continue;
			Recurse(NextSize,StartR+r*NextSize,StartC+c*NextSize);
		}
	}
}

void Print(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cout<<board[r][c];
		}
		cout<<endl;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	Init();
	Recurse(size,0,0);
	Print();
	return 0;
}
