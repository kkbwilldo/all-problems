#include <iostream>
using namespace std;

const int MAX = 55;

int totalCnt;
int ROW,COL;
int curR,curC,curDir;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int map[MAX][MAX];
bool visited[MAX][MAX];

void CleanUp(int r,int c){
	if(visited[r][c]) return; // 청소한 칸으로 이동은 가능하지만 청소는 하지 않음
	visited[r][c]=true;
	totalCnt++;
}

bool isBackOkay(int r,int c,int dir){
	int nextDir=(dir+2)%4;
	int nr=r+dr[nextDir];
	int nc=c+dc[nextDir];
	if(nr<0||nr>=ROW||nc<0||nc>=COL) return false;
	if(map[nr][nc]==1) return false;
	return true;
}

bool isNextOkay(int r,int c,int dir){
	int nextDir=(dir+4-1)%4;
	int nr=r+dr[nextDir];
	int nc=c+dc[nextDir];
	if(nr<0||nr>=ROW||nc<0||nc>=COL) return false;
	if(visited[nr][nc]) return false;
	if(map[nr][nc]==1) return false;
	return true;
}

void Rotate(int dir){
	curDir=(dir+4-1)%4;
}

void Move(int r,int c,int dir){
	curR=r+dr[dir];
	curC=c+dc[dir];
}

void Print(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<visited[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	cin>>curR>>curC>>curDir;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>map[r][c];
		}
	}
	
	while(1){
		CleanUp(curR,curC);
		int cnt=0;
		for(int i=0;i<4;i++){
			if(isNextOkay(curR,curC,curDir)){
				Rotate(curDir);
				Move(curR,curC,curDir);
				break;
			}
			Rotate(curDir);
			cnt++;
		}
		if(cnt==4){
			if(isBackOkay(curR,curC,curDir)){
				Move(curR,curC,(curDir+2)%4);
			}
			else break;
		}
	}
	//Print();
	cout<<totalCnt<<endl;
	return 0;
}
