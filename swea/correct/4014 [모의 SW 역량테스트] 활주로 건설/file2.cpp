// 활주로 건설 
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=25;

int testcase;
int answer;
int mapSize,len;
int board[MAX][MAX],inverted[MAX][MAX];

bool CheckRoad(int map[][MAX],int c){
	int size=1;
	for(int r=0;r<mapSize-1;r++){
		if(map[r][c]==map[r+1][c]) size++;
		else if(map[r][c]+1==map[r+1][c]){
			if(size<len) return false;
			size=1;
		}
		else if(map[r][c]==map[r+1][c]+1){
			int reference=map[r+1][c];
			for(int i=r+1;i<=r+len;i++){
				if(i>=mapSize) return false;
				if(map[i][c]!=reference) return false;
			}
			r=r+len-1;
			size=0;
		}
		else return false;
	}
	return true;
}

void CheckAll(int map[][MAX]){
	for(int c=0;c<mapSize;c++){
		if(CheckRoad(map,c)) answer++;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		memset(inverted,0,sizeof(inverted));
		answer=0;
		cin>>mapSize>>len;
		for(int r=0;r<mapSize;r++){
			for(int c=0;c<mapSize;c++){
				cin>>board[r][c];
				inverted[c][r]=board[r][c];
			}
		}
		CheckAll(board);
		CheckAll(inverted);
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
