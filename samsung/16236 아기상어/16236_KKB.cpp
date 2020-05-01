/*
상어 구조체(위치,크기,먹은 물고기 수,시간),물고기 구조체(위치,거리)를 만든다.

cmp() 함수는 1. 가까운 거리 2. r이 작은 것 3. c가 작은 것 순으로 정렬을 도와주는 함수.

Search()는 상어가 먹을 수 있는 모든 물고기를 찾고 그 물고기까지의 최단 거리들을 계산해준다(BFS).
Search()는 먹을 수 있는 물고기 정보를 school에 담는다.

Move()는 우선 순위가 높은 물고기 위치로 상어를 이동시키며, 상어 정보(위치,먹은 물고기 수,시간,크기)를 업데이트 한다.

Search(),sort(),Move() 순으로 시뮬레이션을 진행하며 더 이상 먹을 수 없는 상태가 되면
상어의 시간을 출력한다.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

struct shark{
	int r,c;
	int size;
	int ate;
	int clk;
	shark():r(-1),c(-1),size(0),ate(0),clk(0){}
	shark(int _r,int _c):r(_r),c(_c),size(2),ate(0),clk(0){}
};

struct fish{
	int r,c;
	int dist;
	fish(int _r,int _c,int _dist):r(_r),c(_c),dist(_dist){}
};

vector <fish> school;

const int MAX = 22;

int size;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int map[MAX][MAX];
bool visited[MAX][MAX];
shark baby;

bool cmp(const fish& a,const fish& b){
	if(a.dist<b.dist) return true;
	else if(a.dist==b.dist){
		if(a.r<b.r) return true;
		else if(a.r==b.r){
			if(a.c<b.c) return true;
		}
	}
	return false;
}

void Search(){
	school.clear();
	memset(visited,0,sizeof(visited));
	queue <fish> q;
	visited[baby.r][baby.c]=true;
	q.push(fish(baby.r,baby.c,0));
	while(!q.empty()){
		int r=q.front().r;
		int c=q.front().c;
		int dist=q.front().dist;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int next=dist+1;
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(map[nr][nc]>baby.size) continue;
			if(visited[nr][nc]) continue;
			q.push(fish(nr,nc,next));
			visited[nr][nc]=true;
			if(0<map[nr][nc]&&map[nr][nc]<baby.size)
				school.push_back(fish(nr,nc,next));
		}
	}
}

void Move(){
	int targetR=school[0].r;
	int targetC=school[0].c;
	map[targetR][targetC]=9;
	map[baby.r][baby.c]=0;
	baby.r=targetR;
	baby.c=targetC;
	baby.ate++;
	baby.clk+=school[0].dist;
	if(baby.ate==baby.size){
		baby.size++;
		baby.ate=0;
	}
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
			if(map[r][c]==9){
				baby=shark(r,c);
			}
		}
	}
	
	Search();	
	while(school.size()>0){
		sort(school.begin(),school.end(),cmp);
		Move();
		Search();
	}
	
	cout<<baby.clk<<endl;
	return 0;
}
