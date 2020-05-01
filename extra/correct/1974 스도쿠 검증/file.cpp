#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX=9;
const int SIZE=3;

int testcase;
int board[MAX][MAX];
bool visited[MAX+1];

bool CheckSerial(string type){
	if(type=="ROW"){
		for(int r=0;r<MAX;r++){
			memset(visited,0,sizeof(visited));
			for(int c=0;c<MAX;c++){
				int num=board[r][c];
				if(visited[num]) return false;
				visited[num]=true;
			}
		}
	}
	else if(type=="COL"){
		for(int c=0;c<MAX;c++){
			memset(visited,0,sizeof(visited));
			for(int r=0;r<MAX;r++){
				int num=board[r][c];
				if(visited[num]) return false;
				visited[num]=true;
			}
		}
	}
	return true;
}

bool CheckCell(){
	for(int i=0;i<MAX;i++){
		int StartR=(i/3)*3; // 핵심 
		int StartC=(i%3)*3;
		memset(visited,0,sizeof(visited));
		for(int r=StartR;r<StartR+SIZE;r++){
			for(int c=StartC;c<StartC+SIZE;c++){
				int num=board[r][c];
				if(visited[num]) return false;
				visited[num]=true;
			}
		}
	}
	return true;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				cin>>board[r][c];
			}
		}
		cout<<"#"<<test<<" ";
		if(!CheckSerial("ROW")) cout<<0<<endl;
		else if(!CheckSerial("COL")) cout<<0<<endl;
		else if(!CheckCell()) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
