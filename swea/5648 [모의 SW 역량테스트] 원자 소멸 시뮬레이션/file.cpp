#include <iostream>
#include <vector>
using namespace std;

const int MAX=4004;

int testcase;
int numAtoms;
int r,c,dir,energy;
int totalEnergy;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

struct atom{
	int r,c,dir,energy;
	bool dead;
	atom(int _r,int _c,int _dir,int _energy): \
	r(_r),c(_c),dir(_dir),energy(_energy),dead(false){}
};

vector <int> board[MAX][MAX];
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
			for(int j=0;j<board[r][c].size();j++){
				if(board[r][c][j]==i){
					board[r][c].erase(board[r][c].begin()+j);//iㄱ가 아니고 J
					break;
				}
			}
			continue;
		}
		// 좌표 업데이트 여기서 하면 틀린다
		board[nr][nc].push_back(i);
		for(int j=0;j<board[r][c].size();j++){
			if(board[r][c][j]==i){
				board[r][c].erase(board[r][c].begin()+j);//iㄱ가 아니고 J
				break;
			}
		}
		atoms[i].r=nr; // ㅇㅕ기서 좌표 업데이트 해야한다
		atoms[i].c=nc;
	}
}

void ClearGones(){
	for(int i=0;i<atoms.size();i++){
		if(atoms[i].dead) continue;
		int r=atoms[i].r;
		int c=atoms[i].c;
		if(board[r][c].size()>1){
			for(int j=0;j<board[r][c].size();j++){
				int idx=board[r][c][j];
				atoms[idx].dead=true;
				totalEnergy+=atoms[idx].energy;
			}
			board[r][c].clear();// ㅇㅕ기서 클리어
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
		for(int r=0;r<MAX;r++){   // 보드 초기화 필요 
			for(int c=0;c<MAX;c++){
				board[r][c].clear();
			}
		}
		totalEnergy=0;
		cin>>numAtoms;
		for(int i=0;i<numAtoms;i++){
			cin>>c>>r>>dir>>energy;
			r+=1000;
			c+=1000;
			r*=2;
			c*=2;
			cout<<"idx: "<<i<<" r,c: "<<r<<","<<c<<endl;
			atoms.push_back(atom(r,c,dir,energy));
			board[r][c].push_back(i); // 보드 입력 
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
