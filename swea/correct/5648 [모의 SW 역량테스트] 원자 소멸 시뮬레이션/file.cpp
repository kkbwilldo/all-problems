#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX=4004;

int testcase;
int numAtoms;
int r,c,dir,energy;
int totalEnergy;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];

struct atom{
	int r,c,dir,energy;
	bool dead;
	atom(int _r,int _c,int _dir,int _energy): \
	r(_r),c(_c),dir(_dir),energy(_energy),dead(false){}
};

vector <atom> atoms;

bool AllGone(){
	for(int i=0;i<atoms.size();i++){
		if(atoms[i].dead==false) return false;
	}
	return true;
}

void Move(){
	for(int i=0;i<atoms.size();i++){
		if(atoms[i].dead) continue;
		int r=atoms[i].r;
		int c=atoms[i].c;
		int dir=atoms[i].dir;
		int nr=r+dr[dir];
		int nc=c+dc[dir];
		if(nr<0||nr>=MAX||nc<0||nc>=MAX){
			atoms[i].dead=true;
			board[r][c]--;
			continue;
		}
		// 좌표 업데이트 여기서 하면 틀린다
		board[nr][nc]++;
		board[r][c]--;
		atoms[i].r=nr; // ㅇㅕ기서 좌표 업데이트 해야한다
		atoms[i].c=nc;
	}
}

void ClearGones(){
	for(int i=0;i<atoms.size();i++){
		if(atoms[i].dead) continue;
		int r=atoms[i].r;
		int c=atoms[i].c;
		if(board[r][c]>1){
			for(int j=0;j<atoms.size();j++){
				if(atoms[j].dead) continue;
				if(atoms[j].r==r&&atoms[j].c==c){
					atoms[j].dead=true;
					totalEnergy+=atoms[j].energy;
				}
			}
			board[r][c]=0;// ㅇㅕ기서 클리어
		}
		// 여기가 아니다 
	}
}

void Print(){
	cout<<"#"<<endl;
	for(int i=0;i<atoms.size();i++){
		if(!atoms[i].dead) cout<<"alive : "<<i<<endl;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		atoms.clear();
		memset(board,0,sizeof(board));
		totalEnergy=0;
		cin>>numAtoms;
		for(int i=0;i<numAtoms;i++){
			int x,y;
			cin>>x>>y>>dir>>energy;
			r=1000-y;
			c=x+1000;
			r*=2;
			c*=2;
			atoms.push_back(atom(r,c,dir,energy));
			board[r][c]++; // 보드 입력 
		}		
		while(1){
			if(AllGone()) break;
			//Print();
			Move();
			ClearGones();
			//Print();
		}		
		cout<<"#"<<test<<" "<<totalEnergy<<endl;
	}
	return 0;
}
