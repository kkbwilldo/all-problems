#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=1510;
const int INF=987987987;

int ROW,COL;
int StartR,StartC,EndR,EndC;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
int costs[MAX][MAX];
bool visited[MAX][MAX];
vector <tuple<int,int> > pos,ice;

void SetCosts(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			costs[r][c]=INF;
		}
	}
	costs[StartR][StartC]=0;
	priority_queue <tuple<int,int,int> > q;
	q.push(make_tuple(0,StartR,StartC));
	while(!q.empty()){
		int cost,r,c;
		tie(cost,r,c)=q.top();
		q.pop();
		cost*=-1;
		if(costs[r][c]<cost) continue;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(costs[nr][nc]<=cost+board[nr][nc]) continue;
			costs[nr][nc]=cost+board[nr][nc];
			if(board[nr][nc]==0) costs[nr][nc]=0;
			q.push(make_tuple(-costs[nr][nc],nr,nc));
		}
	}
}

void MeltDown(){
	for(auto iter=ice.begin();iter!=ice.end();){
		int r,c;
		tie(r,c)=*iter;
		if(costs[r][c]==1){
			costs[r][c]=0;
			iter=ice.erase(iter);
		}
		else{
			costs[r][c]--;
			iter++;
		}
	}
}

void Search(){
	memset(visited,0,sizeof(visited));
	visited[StartR][StartC]=true;
	queue <tuple<int,int> > q;
	q.push(make_tuple(StartR,StartC));
	while(!q.empty()){
		int r,c;
		tie(r,c)=q.front();
		q.pop();
		if(r==EndR&&c==EndC) return;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc]) continue;
			if(costs[nr][nc]!=0) continue;
			visited[nr][nc]=true;
			q.push(make_tuple(nr,nc));
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			char cell;
			cin>>cell;
			if(cell=='.') board[r][c]=0;
			else if(cell=='X') {
				board[r][c]=1;
				ice.push_back(make_tuple(r,c));
			}
			else{
				pos.push_back(make_tuple(r,c));
				board[r][c]=0;
			}
		}
	}
	tie(StartR,StartC)=pos[0];
	tie(EndR,EndC)=pos[1];
	SetCosts();
	int Time=0;
	while(ice.size()>0){
		Search();
		if(visited[EndR][EndC]) break;
		MeltDown();
		Time++;
	}
	cout<<Time<<endl;
	return 0;
}


