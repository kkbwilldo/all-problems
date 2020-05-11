#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int MAX=310;

char board[MAX][MAX];
int testcase,answer;
int size;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1}; // 이거 잘못써서 틀렸다
bool visited[MAX][MAX];


vector <tuple<int,int> > pos;

bool CheckNone(int r,int c){
	for(int i=0;i<8;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0|nr>=size||nc<0||nc>=size) continue;
		if(board[nr][nc]=='*') return false;
	}
	return true;
}

void SetSafePos(){
	pos.clear();
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(board[r][c]=='*') continue; // 이거 안했다 
			if(CheckNone(r,c)) pos.push_back(make_tuple(r,c));
		}
	}
}

void BlowUp(){
	memset(visited,0,sizeof(visited));
	queue <tuple<int,int> > q;
	for(int i=0;i<pos.size();i++){
		int r,c;
		tie(r,c)=pos[i];
		if(visited[r][c]) continue;
		visited[r][c]=true;
		answer++;
		q.push(make_tuple(r,c));		
		while(!q.empty()){
			tie(r,c)=q.front();
			q.pop();
			for(int i=0;i<8;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				if(board[nr][nc]=='*') continue;
				if(visited[nr][nc]) continue;
				visited[nr][nc]=true;
				if(CheckNone(nr,nc)) q.push(make_tuple(nr,nc));
			}
		}
	}
}

void CountRest(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(board[r][c]=='.'&&!visited[r][c]) answer++;
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		answer=0;
		cin>>size;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
			}
		}
		SetSafePos();
		BlowUp();
		CountRest();
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
