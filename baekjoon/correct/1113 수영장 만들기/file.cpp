#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=55;
const int INF=987987987;

int ROW,COL,answer;
int minHeight,maxHeight;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
int board3D[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

pair<bool, vector <pair<int,int> > > Clustering(int StartR,int StartC, int h){
	bool flag=true;
	vector <pair<int,int> > pos;
	queue <pair<int,int> > q;
	q.push(make_pair(StartR,StartC));
	visited[StartR][StartC][h]=true;
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		pos.push_back(make_pair(r,c));
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL){
				flag=false;
				continue;
			}
			if(board3D[nr][nc][h]!=10) continue;
			if(visited[nr][nc][h]) continue;
			visited[nr][nc][h]=true;
			q.push(make_pair(nr,nc));
		}
	}
	return make_pair(flag,pos);
}

void Drain(const vector<pair<int,int> > &pos,int h){
	for(int i=0;i<pos.size();i++){
		int r=pos[i].first;
		int c=pos[i].second;
		board3D[r][c][h]=0;
	}
}

void Print(){
	for(int h=maxHeight;h>=0;h--){
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cout<<board3D[r][c][h]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);

	minHeight=INF;
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			char height;
			cin>>height;
			board[r][c]=height-'0';
			minHeight=min(minHeight,board[r][c]);
			maxHeight=max(maxHeight,board[r][c]);
		}
	}
	
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			for(int h=0;h<=board[r][c];h++) board3D[r][c][h]=1;
			for(int h=board[r][c]+1;h<=maxHeight;h++) board3D[r][c][h]=10;
		}
	}
	
	for(int h=maxHeight;h>=minHeight;h--){
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				if(visited[r][c][h]) continue;
				if(board3D[r][c][h]!=10) continue;
				auto p=Clustering(r,c,h);
				if(!p.first) Drain(p.second,h);
			}
		}
	}
	
	//Print();
	
	for(int h=maxHeight;h>=minHeight;h--){
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				if(board3D[r][c][h]==10) answer++;
			}
		}
	}
	
	cout<<answer<<endl;
	return 0;
}
