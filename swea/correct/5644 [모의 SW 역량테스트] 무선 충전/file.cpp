#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#include <unordered_map>
using namespace std;

const int MAX=14;
const int BOARDSIZE=10;

int testcase,Time,numChargers;
int answer;
int dr[]={0,-1,0,1,0};
int dc[]={0,0,1,0,-1};
int Adirs[110],Bdirs[110];
bool visited[MAX][MAX];

vector <int> board[MAX][MAX];
unordered_map <int,int> bcInfo;

void SetChargers(int x,int y,int chargerIdx,int range){
	memset(visited,0,sizeof(visited));
	queue <tuple<int,int,int> > q;
	visited[x][y]=true;
	board[x][y].push_back(chargerIdx);
	q.push(make_tuple(x,y,range));
	while(!q.empty()){
		int r,c,size;
		tie(r,c,size)=q.front();
		q.pop();
		if(size<=0) continue;
		for(int i=1;i<=4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=BOARDSIZE||nc<0||nc>=BOARDSIZE) continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			board[nr][nc].push_back(chargerIdx);
			q.push(make_tuple(nr,nc,size-1));
		}
	}
}

bool cmp(const int &bcIdx1,const int &bcIdx2){
	if(bcInfo[bcIdx1]>bcInfo[bcIdx2]) return true;
	return false;
}

void Sort(){
	for(int r=0;r<BOARDSIZE;r++){
		for(int c=0;c<BOARDSIZE;c++){
			if(board[r][c].size()>1)
				sort(board[r][c].begin(),board[r][c].end(),cmp);
		}
	}
}

int GetAmount(int ar,int ac,int br,int bc){
	int aIdx=board[ar][ac].size()>0?board[ar][ac][0]:-1;
	int bIdx=board[br][bc].size()>0?board[br][bc][0]:-1;
	int battery=bcInfo[aIdx]+bcInfo[bIdx];
	int aSecond,bSecond,secondIdx;
	secondIdx=aSecond=bSecond=-1;
	if(board[ar][ac].size()>1) aSecond=board[ar][ac][1];
	if(board[br][bc].size()>1) bSecond=board[br][bc][1];
	secondIdx=bcInfo[aSecond]>bcInfo[bSecond]?aSecond:bSecond;//ㅇㅕ기 틀림
	if(aIdx==bIdx) battery+=bcInfo[secondIdx]-bcInfo[aIdx]; // ㅇㅕ기 틀림
	return battery;
}

void Walk(){
	int ar=0,ac=0;
	int br=BOARDSIZE-1,bc=BOARDSIZE-1;
	int T=0;
	answer=0;
	while(T<=Time){
		answer+=GetAmount(ar,ac,br,bc);
		int Adir=Adirs[T]; // ㅁㅏ지막엔 제자리
		int Bdir=Bdirs[T];
		ar+=dr[Adir];ac+=dc[Adir];
		br+=dr[Bdir];bc+=dc[Bdir];
		T++;
	}
}

void Init(){
	bcInfo.clear();
	bcInfo[-1]=0;
	for(int r=0;r<BOARDSIZE;r++){
		for(int c=0;c<BOARDSIZE;c++){
			board[r][c].clear();
		}
	}
	memset(Adirs,0,sizeof(Adirs));
	memset(Bdirs,0,sizeof(Bdirs));
}

void Print(){
	for(int r=0;r<BOARDSIZE;r++){
		for(int c=0;c<BOARDSIZE;c++){
			if(board[r][c].size()==0) cout<<"0 ";
			else cout<<board[r][c][0]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		Init();
		cin>>Time>>numChargers;
		for(int t=0;t<Time;t++) cin>>Adirs[t];
		for(int t=0;t<Time;t++) cin>>Bdirs[t];
		for(int i=1;i<=numChargers;i++){
			int r,c,size,charge;
			cin>>c>>r>>size>>charge;  // r,c 반대로 주어진다!!!!
			SetChargers(r-1,c-1,i,size); // 위치 조심!!!
			bcInfo[i]=charge;
		}
		Sort();
		//Print();
		Walk();
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
