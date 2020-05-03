#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=10;

int testcase,size;
int board[MAX][MAX],once[MAX][MAX],twice[MAX][MAX],thrice[MAX][MAX];

void Rot(int map[][MAX]){
	int temp[MAX][MAX];
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			temp[r][c]=map[size-1-c][r]; // size-c가 아니라 size-1-c 이다 
		}
	}
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			map[r][c]=temp[r][c];
		}
	}
}

void Print(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cout<<once[r][c];
		}
		cout<<" ";
		for(int c=0;c<size;c++){
			cout<<twice[r][c];
		}
		cout<<" ";
		for(int c=0;c<size;c++){
			cout<<thrice[r][c];
		}
		cout<<endl;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(once,0,sizeof(once));
		memset(twice,0,sizeof(twice));
		memset(thrice,0,sizeof(thrice));
		memset(board,0,sizeof(board));
		cin>>size;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
				once[r][c]=twice[r][c]=thrice[r][c]=board[r][c];
			}
		}
		Rot(once);
		Rot(twice);Rot(twice);
		Rot(thrice);Rot(thrice);Rot(thrice);
		cout<<"#"<<test<<endl;
		Print();
	}
	return 0;
}
