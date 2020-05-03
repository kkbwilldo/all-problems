#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=310;

char board[MAX][MAX];
int testcase,size,answer;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};
int score[MAX][MAX];

// 우선순위 큐 정렬 방식 
struct cmp{
	bool operator()(tuple <int,int,int> &a,tuple <int,int,int> &b){
		return get<2>(a) > get<2>(b);
	}
};

priority_queue <tuple<int,int,int>,vector<tuple<int,int,int> >,cmp > pos; // 우선순위 큐 사용 

void FindSafeZone(){ // O(N^2)
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(board[r][c]=='*') continue; // 이거 안해서 틀렸다!!! 
			int numMines=0;
			for(int i=0;i<8;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				if(board[nr][nc]=='*') numMines++;
			}
			if(!numMines) pos.push(make_tuple(r,c,1));
		}
	}
}

bool ClickAndFindSafeZone(int r,int c){ // O(1)
	vector <pair<int,int> > availables;
	int numMines=0;
	for(int i=0;i<8;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0||nr>=size||nc<0||nc>=size) continue;
		if(score[nr][nc]!=-1) continue;
		if(board[nr][nc]=='*') numMines++;
		else availables.push_back(make_pair(nr,nc));
	}
	score[r][c]=numMines;
	if(score[r][c]) return false;
	for(int i=0;i<availables.size();i++){
		int x=availables[i].first;
		int y=availables[i].second;
		pos.push(make_tuple(x,y,0));
	}
	return true;
}

void SearchMap(){
	while(!pos.empty()){
		int r,c,clickCount;
		tie(r,c,clickCount)=pos.top();
		pos.pop();
		if(score[r][c]!=-1) continue;
		if(clickCount) answer++;
		ClickAndFindSafeZone(r,c);  // O(1)
	}
	for(int r=0;r<size;r++){ // O(N^2)
		for(int c=0;c<size;c++){
			if(board[r][c]=='.'&&score[r][c]==-1) answer++;
		}
	}
}

void Init(){
	memset(board,0,sizeof(board));
	memset(score,-1,sizeof(score));
	answer=0;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		Init();
		cin>>size;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
			}
		}
		FindSafeZone(); // O(N^2)
		SearchMap();
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
