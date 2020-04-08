#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;

const int MAX = 55;

char sequence[12];
int ROW,COL;
int numDrops,numGreens,numReds;
int numFlowers,maxVal;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
int dists[MAX][MAX];
bool blossomed[MAX][MAX];

vector <int> indice,dropPos;
vector <tuple<int,int> > possible;
queue <tuple<int,int,char,int> > q;

void bfs(){
	while(!q.empty()){
		int r,c,dist;
		char color;
		tie(r,c,color,dist)=q.front();
		q.pop();
		if(dists[r][c]==0){
			if(color=='g') dists[r][c]=-dist;
			else dists[r][c]=dist;
		}
		else{
			if(color=='g'&&dists[r][c]==-dist){
				numFlowers++;
				blossomed[r][c]=true;
				continue;
			}
			else if(color=='r'&&dists[r][c]==-dist){
				numFlowers++;
				blossomed[r][c]=true;
				continue;
			}
		}
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int ndist=color=='g'?dist-1:dist+1;
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(map[nr][nc]==0) continue;
			if(blossomed[nr][nc]) continue;
			q.push(make_tuple(nr,nc,color,ndist));
		}
	}
}

void dfs(int depth,int numGreens,int numReds){
	if(depth==numDrops){
		while(!q.empty()) q.pop();
		numFlowers=0;
		for(int i=0;i<depth;i++){
			int idx=dropPos[i];
			int r,c;
			tie(r,c)=possible[idx];
			char color=sequence[i];
			q.push(make_tuple(r,c,color,0));
		}
		memset(blossomed,0,sizeof(blossomed));
		bfs();
		cout<<"numFlowers: "<<numFlowers<<endl;
		maxVal=max(maxVal,numFlowers);
		return;
	}
	if(numGreens>0){
		sequence[depth]='g';
		dfs(depth+1,numGreens-1,numReds);
	}
	if(numReds>0){
		sequence[depth]='r';
		dfs(depth+1,numGreens,numReds-1);
	}
}

void AllCases(){
	for(int i=0;i<possible.size()-numDrops;i++) indice.push_back(0);
	for(int i=0;i<numDrops;i++) indice.push_back(1);
	do{
		dropPos.clear();
		for(int i=0;i<indice.size();i++){
			if(indice[i]) dropPos.push_back(i);
		}
		dfs(0,numGreens,numReds);
	}while(next_permutation(indice.begin(),indice.end()));
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>numGreens>>numReds;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>map[r][c];
			if(map[r][c]==2) possible.push_back(make_tuple(r,c));
		}
	}
	AllCases();
	cout<<maxVal<<endl;
	return 0;
}
