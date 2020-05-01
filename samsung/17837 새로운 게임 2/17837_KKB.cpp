#include <iostream>
#include <vector>
using namespace std;

const int MAX = 15;

int size,numUnits;
int r,c,dir;
int answer;
int dr[]={0,0,0,-1,1};
int dc[]={0,1,-1,0,0};
int board[MAX][MAX];
bool isOver;

struct unit{
	int r,c,dir;
	unit(int _r,int _c,int _dir):r(_r),c(_c),dir(_dir){}
};

vector <unit> units;
vector <int> unitMap[MAX][MAX];

void ChangeDir(int unitNum){
	if(units[unitNum].dir%2==0) units[unitNum].dir--;
	else units[unitNum].dir++;
}

int CheckNext(int unitNum){
	int nr=units[unitNum].r+dr[units[unitNum].dir];
	int nc=units[unitNum].c+dc[units[unitNum].dir];
	if(nr<0||nr>=size||nc<0||nc>=size) return 1; // 맵 밖
	else if(board[nr][nc]==0) return 2;          // 흰색 영역
	else if(board[nr][nc]==1) return 3;          // 빨간색 영역
	else if(board[nr][nc]==2) return 4;          // 파란색 영역 
	return -1;
}

bool IsOver(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(unitMap[r][c].size()>=4) return true;
		}
	}
	return false;
}

int FindIdx(int unitNum){
	int r=units[unitNum].r;
	int c=units[unitNum].c;
	for(int idx=0;idx<unitMap[r][c].size();idx++){
		if(unitMap[r][c][idx]==unitNum) return idx;
	}
	return -1;
}

void Move(int unitNum){
	int unitIdx=FindIdx(unitNum);
	int type=CheckNext(unitNum);
	int r=units[unitNum].r;
	int c=units[unitNum].c;
	int dir=units[unitNum].dir;
	int nr=r+dr[dir];
	int nc=c+dc[dir];
	if(type==2){
		for(int i=unitIdx;i<unitMap[r][c].size();i++){
			int num=unitMap[r][c][i];
			unitMap[nr][nc].push_back(num);
			units[num].r=nr;
			units[num].c=nc;
		}
		unitMap[r][c].erase(unitMap[r][c].begin()+unitIdx,unitMap[r][c].end());
	}
	else if(type==3){
		for(int i=unitMap[r][c].size()-1;i>=unitIdx;i--){
			int num=unitMap[r][c][i];
			unitMap[nr][nc].push_back(num);
			units[num].r=nr;
			units[num].c=nc;
		}
		unitMap[r][c].erase(unitMap[r][c].begin()+unitIdx,unitMap[r][c].end());
	}
}

void Turn(){
	for(int i=1;i<=numUnits;i++){
		int type=CheckNext(i);
		if(type==1||type==4){
			ChangeDir(i);
			type=CheckNext(i);
			if(type==2||type==3) Move(i);
		}
		else Move(i);
		if(IsOver()){
			isOver=true;
			return;
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	units.push_back(unit(-1,-1,-1));
	
	cin>>size>>numUnits;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>board[r][c];
		}
	}
	
	for(int i=1;i<=numUnits;i++){
		cin>>r>>c>>dir;
		r--;c--;
		units.push_back(unit(r,c,dir));
		unitMap[r][c].push_back(i);
	}
	
	answer=1;
	while(answer<=1000){
		isOver=false;
		Turn();
		if(isOver) break;
		answer++;
	}
	if(answer>1000) answer=-1;
	
	cout<<answer<<endl;
	return 0;
}
