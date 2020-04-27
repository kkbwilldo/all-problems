#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=20;

int ROW,COL,shootRange;
int maxVal,kills;
int dr[]={0,-1,0};
int dc[]={-1,0,1};
int board[MAX][MAX],origin[MAX][MAX];
bool visited[MAX][MAX];

vector <int> Pos;
vector <pair<int,int> > Killed;

void Shoot(){
	Killed.clear();
	for(int i=0;i<3;i++){
		memset(visited,0,sizeof(visited));
		queue <tuple<int,int,int> > q;
		q.push(make_tuple(ROW-1,Pos[i],1));
		visited[ROW-1][Pos[i]]=true;
		while(!q.empty()){
			int r,c,range;
			tie(r,c,range)=q.front();
			q.pop();
			if(board[r][c]==1){
				Killed.push_back(make_pair(r,c));
				break;
			}
			if(range>=shootRange) continue;
			for(int j=0;j<3;j++){
				int nr=r+dr[j];
				int nc=c+dc[j];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
				if(visited[nr][nc]) continue;
				q.push(make_tuple(nr,nc,range+1));
			}
		}
	}
}

void CountKills(){
	sort(Killed.begin(),Killed.end());
	Killed.erase(unique(Killed.begin(),Killed.end()),Killed.end());
	kills+=Killed.size();
	for(int i=0;i<Killed.size();i++){
		int r=Killed[i].first;
		int c=Killed[i].second;
		board[r][c]=0;
	}
}

void PullDown(){
	for(int c=0;c<COL;c++){
		for(int r=ROW-2;r>=0;r--){
			board[r+1][c]=board[r][c];
		}
	}
	for(int c=0;c<COL;c++) board[0][c]=0;
}

void Copy(int map[][MAX],int origin[][MAX]){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			map[r][c]=origin[r][c];
		}
	}
}

void AllCases(){
	vector <int> indice;
	for(int i=0;i<COL-3;i++) indice.push_back(0);
	for(int i=0;i<3;i++) indice.push_back(1);
	do{
		Copy(board,origin);
		Pos.clear();
		kills=0;
		for(int c=0;c<COL;c++){
			if(indice[c]) Pos.push_back(c);
		}
		for(int r=0;r<ROW;r++){
			Shoot();
			CountKills();
			PullDown();
		}
		maxVal=max(maxVal,kills);
	}while(next_permutation(indice.begin(),indice.end()));
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>shootRange;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
			origin[r][c]=board[r][c];
		}
	}
	AllCases();
	cout<<maxVal<<endl;
	return 0;
}
