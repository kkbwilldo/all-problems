#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const int MAX=23;

int testcase,maxVal;
int size,fee;
int costs[MAX];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX];

void Init(){
	for(int k=1;k<MAX;k++){
		costs[k]=k*k+(k-1)*(k-1);
	}
}

void SpreadRange(int StartR,int StartC){
	memset(visited,0,sizeof(visited));
	int numHouses=0;
	queue <pair<int,int> > q;
	q.push(make_pair(StartR,StartC));
	int Range=1;
	visited[StartR][StartC]=true;
	while(!q.empty()){
		if(Range>size+1) break;
		int qSize=q.size();
		for(int i=0;i<qSize;i++){
			int r=q.front().first;
			int c=q.front().second;
			q.pop();
			if(board[r][c]==1) numHouses++;
			for(int j=0;j<4;j++){
				int nr=r+dr[j];
				int nc=c+dc[j];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				if(visited[nr][nc]) continue;
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
		if(fee*numHouses>=costs[Range]) maxVal=max(maxVal,numHouses);
		Range++;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	Init();
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		maxVal=0;
		cin>>size>>fee;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
			}
		}
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				SpreadRange(r,c);
			}
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
