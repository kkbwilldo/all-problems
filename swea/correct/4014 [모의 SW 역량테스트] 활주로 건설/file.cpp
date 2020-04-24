#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=22;

int testcase,answer;
int size,len;
int board[MAX][MAX],inverted[MAX][MAX];

void CheckRoad(int map[][MAX],int c){
	int possibleSize=1;
	for(int r=0;r<size-1;r++){
		if(map[r][c]+1==map[r+1][c]){
			if(possibleSize<len) return;
			possibleSize=1;//possibleSize=1 하면 틀린드
		}
		else if(map[r][c]==map[r+1][c]+1){
			int reference=map[r+1][c];
			for(int i=1;i<=len;i++){
				int nr=r+i;
				if(nr<0||nr>=size) return;
				if(map[nr][c]!=reference) return;
			}
			r+=len-1;//-1을 해줘야 다음 위치가 r+len이 된다// 여기서 틀렸다!!!!!!
			possibleSize=0;
		}
		else if(map[r][c]==map[r+1][c]) possibleSize++;
		else return;
	}
	answer++;
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
		cin>>size>>len;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
				//inverted[size-c][r]=board[r][c];
				inverted[c][r]=board[r][c];
			}
		}
		for(int c=0;c<size;c++){
			CheckRoad(board,c);
			CheckRoad(inverted,c);
		}
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
