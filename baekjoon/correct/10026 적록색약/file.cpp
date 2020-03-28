#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

const int MAX = 110;

char color;
char map[MAX][MAX];
int size,maxIdx,labelIdx;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int label[MAX][MAX];
bool visited[MAX][MAX];

vector <int> cnts;
vector <pair<int,int> > blues;

void bfs(int x,int y){
	visited[x][y]=true;
	color=map[x][y];
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		label[r][c]=labelIdx;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(visited[nr][nc]) continue;
			if(map[nr][nc]==color){
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

void RGbfs(int x,int y){
	visited[x][y]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		label[r][c]=labelIdx;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(visited[nr][nc]) continue;
			if(map[nr][nc]=='R'||map[nr][nc]=='G'){
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

void Blue(){
	memset(visited,0,sizeof(visited));
	memset(label,0,sizeof(label));
	labelIdx=1;
	for(int i=0;i<blues.size();i++){
		int r=blues[i].first;
		int c=blues[i].second;
		if(visited[r][c]) continue;
		bfs(r,c);
		labelIdx++;
	}
}

void Red(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]=='R'){
				if(visited[r][c]) continue;
				bfs(r,c);
				labelIdx++;
			}
		}
	}
}

void Green(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]=='G'){
				if(visited[r][c]) continue;
				bfs(r,c);
				labelIdx++;
			}
		}
	}
}

void RedGreen(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]!='B'){
				if(visited[r][c]) continue;
				RGbfs(r,c);
				labelIdx++;
			}
		}
	}
}

int MaxIdx(){
	maxIdx=0;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(maxIdx<label[r][c]) maxIdx=label[r][c];
		}
	}
	return maxIdx;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>map[r][c];
			if(map[r][c]=='B') blues.push_back(make_pair(r,c));
		}
	}
	
	Blue();
	Red();
	Green();
	cnts.push_back(MaxIdx());
	Blue();
	RedGreen();
	cnts.push_back(MaxIdx());
	for(int i=0;i<cnts.size();i++) cout<<cnts[i]<<" ";
	cout<<endl;
	return 0;
}
