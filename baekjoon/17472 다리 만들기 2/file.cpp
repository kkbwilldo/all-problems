#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#define endl '\n'
#define MAX 12
#define ISLAND 7
#define INF 987987987
using namespace std;

int ROW,COL,minDist;
int numIslands,cnt;
int totalDist;
int indice[5*4*3*2*1];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
int label[MAX][MAX];
int distances[ISLAND][ISLAND];
bool visitedNode[ISLAND];   // 섬 방문
bool visited[MAX][MAX]; // 땅 방문 

vector <int> connectList[ISLAND];
vector <pair<int,int> > temp;
vector <pair<pair<int,int>,int> > bridges;
vector <vector <pair<int,int> > > position;

// 섬 구역 나누기 
void Labeling(){
	memset(visited,0,sizeof(visited));
	position.push_back(temp);
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]!=1) continue;
			if(visited[r][c]) continue;
			numIslands++;
			position.push_back(temp);
			visited[r][c]=true;
			queue <pair<int,int> > q;
			q.push(make_pair(r,c));
			while(!q.empty()){
				int x=q.front().first;
				int y=q.front().second;
				q.pop();
				// 각 섬의 땅 좌표를 position에 저장 
				position[numIslands].push_back(make_pair(x,y));
				label[x][y]=numIslands;
				for(int i=0;i<4;i++){
					int nx=x+dr[i];
					int ny=y+dc[i];
					if(nx<0||nx>=ROW||ny<0||ny>=COL) continue;
					if(visited[nx][ny]) continue;
					if(map[nx][ny]==0) continue;
					visited[nx][ny]=true;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

// 섬 사이 길이 2 이상인 최단거리 구하기 
void FindShortestPath(){
	for(int islandIdx=1;islandIdx<position.size();islandIdx++){
		for(int idx=0;idx<position[islandIdx].size();idx++){
			int r=position[islandIdx][idx].first;
			int c=position[islandIdx][idx].second;
			for(int h=0;h<4;h++){
				int dist=0;
				int nr=r;
				int nc=c;
				while(1){
					nr+=dr[h];// i가 아니고 h이다
					nc+=dc[h];
					if(nr<0||nr>=ROW||nc<0||nc>=COL) break;
					int nextIdx=label[nr][nc];
					if(nextIdx==islandIdx) continue;
					else if(nextIdx==0) dist++;
					else{
						if(dist<2) break;
						if(distances[islandIdx][nextIdx]==0){
							distances[islandIdx][nextIdx]=dist;
							distances[nextIdx][islandIdx]=dist;
							break;
						}
						else{
							int nextDist=min(distances[islandIdx][nextIdx],dist);
							distances[islandIdx][nextIdx]=nextDist;
							distances[nextIdx][islandIdx]=nextDist;
							break;
						}
					}
				}
			}
		}
	}
}

// 길이 2 이상인 다리 리스트 만들기 
void MakeCombVector(){
	for(int i=1;i<=numIslands-1;i++){
		for(int j=i+1;j<=numIslands;j++){
			int dist=distances[i][j];
			if(dist>0){
				bridges.push_back(make_pair(make_pair(i,j),dist));
			}
		}
	}
}

// 시작섬 1에서 출발하여 나머지 모든 섬에 도착하는지 확인 
void Search(){
	memset(visitedNode,0,sizeof(visitedNode));
	cnt=0; // 섬 개수 
	totalDist=0;
	int Start=1;
	visitedNode[Start]=true;
	queue <int> q;
	q.push(Start);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;
		for(int i=0;i<connectList[node].size();i++){
			int next=connectList[node][i];
			if(visitedNode[next]) continue;
			visitedNode[next]=true;
			totalDist+=distances[node][next];
			q.push(next);
		}
	}
}

void ConnectBridge(int depth,int sum){
	if(depth==bridges.size()){
		if(sum<1) return; // 최소 1개 다리 뽑기
		for(int i=0;i<connectList.size();i++) connectList[i].clear();
		for(int i=0;i<bridges.size();i++){
			if(indice[i]!=1) continue;
			int a=bridges[i].first.first;
			int b=bridges[i].first.second;
			int dist=bridges[i].second;
			connectList[a].push_back(b);
			connectList[b].push_back(a);
		}
		Search();
		if(cnt==numIslands) minDist=min(minDist,totalDist);
	}
	else{
		indice[depth]=0;
		ConnectBridge(depth+1,sum);
		indice[depth]=1;
		ConnectBridge(depth+1,sum+1);
	}
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
	minDist=INF;
	Labeling();
	FindShortestPath();
	///*
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<label[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
	
	for(int i=1;i<=numIslands;i++){
		for(int j=1;j<=numIslands;j++){
			cout<<distances[i][j]<<" ";
		}cout<<endl;
	}
	//*/
	/*
	vector <pair<int,int> >::iterator iter;
	for(int i=1;i<=position.size();i++){
		cout<<"island number:"<<i<<" ";
		for(iter=position[i].begin();iter!=position[i].end();iter++){
			cout<<iter->first<<","<<iter->second<<" ";
		}cout<<endl;
	}
	*/
	MakeCombVector();
	ConnectBridge(0,0);
	if(minDist==INF) minDist=-1;
	cout<<minDist<<endl;
	return 0;
}
