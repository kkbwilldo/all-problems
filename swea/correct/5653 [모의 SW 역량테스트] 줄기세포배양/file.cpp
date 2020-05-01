#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX = 500;
const int PAD = 150;

int testcase,answer;
int ROW,COL,LIMIT;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];

struct cell{
	int r,c,energy; // 시간과 상관 없이 매번 불러서 점수 깎음
	int sleepPoint,activatePoint; // 다 깎이면 다음 상태로 넘어감
	cell(int _r,int _c,int _e):r(_r),c(_c),energy(_e){
		sleepPoint=activatePoint=energy;
	}
};

bool cmp(const cell &a,const cell &b){
	return a.energy>b.energy;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		answer=0;
		cin>>ROW>>COL>>LIMIT;
		vector <cell> cells;
		queue <cell> q;
		for(int r=PAD;r<PAD+ROW;r++){
			for(int c=PAD;c<PAD+COL;c++){
				cin>>board[r][c];
				if(1<=board[r][c]&&board[r][c]<=10){
					cells.push_back(cell(r,c,board[r][c]));
				}
			}
		}
		sort(cells.begin(),cells.end(),cmp); // 시작할 때 한 번만 정렬해주면 된다 		
		for(int i=0;i<cells.size();i++) q.push(cells[i]);
		int Time=0;
		while(!q.empty()){
			if(Time>=LIMIT) break;
			int curQSize=q.size();
			for(int i=0;i<curQSize;i++){
				cell frontCell=q.front();
				q.pop();
				if(frontCell.sleepPoint>0){
					frontCell.sleepPoint--;
					q.push(frontCell);
					continue;
				}
				if(frontCell.activatePoint==frontCell.energy){
					for(int j=0;j<4;j++){
						int nr=frontCell.r+dr[j];
						int nc=frontCell.c+dc[j];
						if(board[nr][nc]!=0) continue;
						board[nr][nc]=frontCell.energy;
						q.push(cell(nr,nc,board[nr][nc]));
					}
				}
				frontCell.activatePoint--;
				if(frontCell.activatePoint>0) q.push(frontCell); // 죽은 세포는 넣지 않음
			}
			Time++;
		}
		answer=q.size(); // q에는 비활성 세포와 활성 세포만 들어있음
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
