#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

const int MAX = 25;

int ROW,COL,maxVal,labelIdx;
int R,C;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX],label[MAX][MAX];
bool canKill;
bool visited[MAX][MAX];

vector <int> Spots;
vector <pair<int,int> > FreeSpots;
vector <pair<int,int> > Puts;
vector <pair<int,int> > temp;
vector <vector <pair<int,int> > > pos;

void FindSpace(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]==0){
				FreeSpots.push_back(make_pair(r,c));
			}
		}
	}
}

void bfs(int x,int y){
	temp.clear();
	visited[x][y]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		temp.push_back(make_pair(r,c));
		label[r][c]=labelIdx;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc]) continue;
			if(map[nr][nc]!=2) continue;
			visited[nr][nc]=true;
			q.push(make_pair(nr,nc));
		}
	}
	pos.push_back(temp);
}

void Labeling(){
	memset(label,0,sizeof(label));
	memset(visited,0,sizeof(visited));
	pos.clear();
	labelIdx=1;
	pos.push_back(temp);
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]==2&&!visited[r][c]){
				bfs(r,c);
				labelIdx++;
			}
		}
	}
}

void Kill(){
	int cnt=0;
	for(int i=1;i<pos.size();i++){
		canKill=true;
		for(int j=0;j<pos[i].size();j++){
			int r=pos[i][j].first;
			int c=pos[i][j].second;
			for(int h=0;h<4;h++){
				int nr=r+dr[h];
				int nc=c+dc[h];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
				if(map[nr][nc]==0){
					canKill=false;
					break;
				}
			}
			if(!canKill) break;
		}
		if(canKill) cnt+=pos[i].size();
	}
	maxVal=max(maxVal,cnt);
}

void PutRock(){
	for(int i=0;i<FreeSpots.size()-2;i++)
		Spots.push_back(0);
	for(int i=0;i<2;i++)
		Spots.push_back(1);
	do{
		Puts.clear();
		for(int i=0;i<Spots.size();i++){
			if(Spots[i]==1){
				R=FreeSpots[i].first;
				C=FreeSpots[i].second;
				Puts.push_back(make_pair(R,C));
				map[R][C]=1;
			}
		}
		Labeling();
		Kill();
		for(int i=0;i<2;i++){
			R=Puts[i].first;
			C=Puts[i].second;
			map[R][C]=0;
		}
	}while(next_permutation(Spots.begin(),Spots.end()));
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>map[r][c];
		}
	}
	
	FindSpace();
	PutRock();
	
	cout<<maxVal<<endl;
	
	return 0;
}
