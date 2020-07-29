#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=1001;
const int INF=987987987;

int testcase,answer;
int ROW,COL,StartR,StartC;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char board[MAX][MAX];
int times[MAX][MAX];
int visited[MAX][MAX];

int Check(){
	answer=INF;
	for(int c=0;c<COL;c++){
		if(visited[0][c]!=INF) answer=min(answer,visited[0][c]);
		if(visited[ROW-1][c]!=INF) answer=min(answer,visited[ROW-1][c]);
	}
	for(int r=1;r<ROW-1;r++){
		if(visited[r][0]!=INF) answer=min(answer,visited[r][0]);
		if(visited[r][COL-1]!=INF) answer=min(answer,visited[r][COL-1]);
	}
	return answer;
}

void Board(){
	cout<<"Board"<<endl;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<board[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void Visited(){
	cout<<"Visited"<<endl;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(visited[r][c]==INF) cout<<-1<<" ";
			else{
				if(0<=visited[r][c]&&visited[r][c]<10) cout<<0;
				cout<<visited[r][c]<<" ";
			}
			}cout<<endl;
		}cout<<endl;
	}

void Times(){
	cout<<"Times"<<endl;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(times[r][c]==INF) cout<<-1<<" ";
			else{
				if(0<=times[r][c]&&times[r][c]<10) cout<<0;
				cout<<times[r][c]<<" ";
			}
		}cout<<endl;
	}cout<<endl;
}

void Init(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			board[r][c]=0;
			times[r][c]=INF;
			visited[r][c]=INF;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("input.txt","r",stdin);
    
	cin>>testcase;
	for(int test=1;test<=testcase;test++){	
		vector <pair<int,int> > fires;
		cin>>COL>>ROW;
		Init();
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>board[r][c];
				if(board[r][c]=='@'){
					StartR=r;
					StartC=c;
				}
				else if(board[r][c]=='*'){
					fires.push_back(make_pair(r,c));
				}
			}
		}
		
		
		/*
		먼저 불이 지나가는 곳의 시간을 체크
		그다음 상근이가 시간마다 갈 수 있는 곳 체크
		마지막으로 테두리에 상근이가 갈 수 있는지 체크
		*/
		queue <tuple<int,int,int> > q;
		for(int i=0;i<fires.size();i++){
			int r=fires[i].first;
			int c=fires[i].second;
			q.push(make_tuple(r,c,1));
			times[r][c]=1;
		}
		while(!q.empty()){
			// 시작점이 여러곳이므로
			int size=q.size();
			for(int i=0;i<size;i++){
				int r,c,cnt;
				tie(r,c,cnt)=q.front();
				q.pop();
				for(int j=0;j<4;j++){
					int nr=r+dr[j];
					int nc=c+dc[j];
					int ncnt=cnt+1;
					if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
					if(board[nr][nc]=='#') continue;
					if(times[nr][nc]!=INF) continue; // -1로하면 틀린다
					times[nr][nc]=ncnt;
					q.push(make_tuple(nr,nc,ncnt));
				}
			}
		}

		queue <tuple<int,int,int> > Sang;
		Sang.push(make_tuple(StartR,StartC,1));
		visited[StartR][StartC]=1;
		while(!Sang.empty()){
			int r,c,cnt;
			tie(r,c,cnt)=Sang.front();
			Sang.pop();			
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				int ncnt=cnt+1;
				if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
				if(board[nr][nc]=='#') continue;
				if(times[nr][nc]<=ncnt) continue;
				if(visited[nr][nc]!=INF) continue;
				visited[nr][nc]=ncnt;
				Sang.push(make_tuple(nr,nc,ncnt));
			}
		}
		
		/*
		cout<<test<<endl;
		Board();
		Visited();
		Times();
		*/
		
		if(Check()!=INF) cout<<answer<<endl;
		else cout<<"IMPOSSIBLE"<<endl; 
	}
	return 0;
}

