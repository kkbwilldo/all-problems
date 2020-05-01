#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 53;

int size,lower,upper;
int moveCnt;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int populations[MAX][MAX];
int opens[MAX][MAX];
bool visited[MAX][MAX];

vector <pair<int,int> > pos;

bool CheckOpen(){
	memset(opens,0,sizeof(opens));
	bool isOpen=false;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			int population=populations[r][c];
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				int nextPop=populations[nr][nc];
				int diff=abs(population-nextPop);
				if(lower<=diff&&diff<=upper){
					int val=1<<i;
					opens[r][c]|=val;
					isOpen=true;
				}
			}
		}
	}
	return isOpen;
}

void Move(int x,int y){
	visited[x][y]=true;
	pos.clear();
	int sum=populations[x][y];
	int cnt=1;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		pos.push_back(make_pair(r,c));
		for(int i=0;i<4;i++){
			bool isOpen=opens[r][c]&(1<<i);
			if(!isOpen) continue;
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(visited[nr][nc]) continue;
			sum+=populations[nr][nc];
			cnt++;
			visited[nr][nc]=true;
			q.push(make_pair(nr,nc));
		}
	}
	int avg=sum/cnt;
	for(int i=0;i<pos.size();i++){
		int r=pos[i].first;
		int c=pos[i].second;
		populations[r][c]=avg;
	}
}

void Exodus(){
	memset(visited,0,sizeof(visited));
	moveCnt++;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(visited[r][c]) continue;
			if(opens[r][c]==0) continue;
			Move(r,c);
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>lower>>upper;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>populations[r][c];
		}
	}
	while(CheckOpen()) Exodus();
	
	cout<<moveCnt<<endl;
	return 0;
}

