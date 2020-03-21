/*
상어 정보를 담는 구조체를 만들고, Fisher(),Catch(),Swim(),Arrange()로 모듈화하여 시뮬레이션 진행

Fisher():
어부 위치 이동.

Catch():
r=1부터 r=ROW까지 이동하면서 가장 가까운 상어를 잡는다.
잡은 상어의 크기를 total에 추가하고
잡은 상어의 살아있음을 죽음으로 표기.
상어맵에서 해당 위치의 인덱스 모두 제거.

Swim():
상어맵 전체 초기.
sharks에서 살아있는 상어를 대상으로
진행방향 상하,좌우로 경우를 나누어
이동했을 때 최종 위치를 계산.
해당 상어의 위치값을 업데이트하고
상어맵에 해당 상어 인덱스 푸쉬

Arrange():
상어맵 전체를 탐색하며 인덱스 개수가 2이상인 위치 탐색.
해당 상어맵 위치를 상어 크기로 내림차순 정렬
maxIdx를 크기가 가장 큰 상어로 설정하고
나머지 상어 모두 죽음 처리
해당 상어맵 위치 클리어 한 후
maxIdx만 상어맵에 푸쉬

*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 110;

struct shark{
	int r,c;
	int speed;
	int dir;
	int size;
	bool live;
	shark(int _r,int _c,int _speed,int _dir,int _size):\
	r(_r),c(_c),speed(_speed),dir(_dir),size(_size),live(true){}
};

int ROW,COL,numSharks;
int person;
int total;
int r,c,speed,dir,size;
int maxIdx;

int dr[]={0,-1,1,0,0};
int dc[]={0,0,0,1,-1};

vector <int> map[MAX][MAX];
vector <shark> sharks;

bool cmp(const int& a,const int& b){
	if(sharks[a].size>sharks[b].size) return true;
	return false;
}

void Fisher(){
	person++;
}

void Catch(){
	for(int r=1;r<=ROW;r++){
		if(map[r][person].size()>0){
			int idx=map[r][person][0];
			total+=sharks[idx].size;
			sharks[idx].live=false;
			map[r][person].clear();
			return;
		}
	}
}

void Swim(){
	for(int r=1;r<=ROW;r++){
		for(int c=1;c<=COL;c++){
			map[r][c].clear();
		}
	}
	for(int i=0;i<numSharks;i++){
		if(!sharks[i].live) continue;
		if(sharks[i].dir>=3){
			for(int j=0;j<sharks[i].speed%((COL-1)*2);j++){
				int nc=sharks[i].c+dc[sharks[i].dir];
				if(nc<1||nc>COL){
					if(sharks[i].dir%2==0) sharks[i].dir-=1;
					else sharks[i].dir+=1;
				}
				sharks[i].c+=dc[sharks[i].dir];
			}
		}
		else {
			for(int j=0;j<sharks[i].speed%((ROW-1)*2);j++){
				int nr=sharks[i].r+dr[sharks[i].dir];
				if(nr<1||nr>ROW){
					if(sharks[i].dir%2==0) sharks[i].dir-=1;
					else sharks[i].dir+=1;
				}
				sharks[i].r+=dr[sharks[i].dir];
			}
		}
		map[sharks[i].r][sharks[i].c].push_back(i);
	}
}

void Arrange(){
	for(int r=1;r<=ROW;r++){
		for(int c=1;c<=COL;c++){
			if(map[r][c].size()>1){
				sort(map[r][c].begin(),map[r][c].end(),cmp);
				maxIdx=map[r][c][0];
				for(int i=1;i<map[r][c].size();i++){
					int idx=map[r][c][i];
					sharks[idx].live=false;
				}
				map[r][c].clear();
				map[r][c].push_back(maxIdx);
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>numSharks;
	for(int i=0;i<numSharks;i++){
		cin>>r>>c>>speed>>dir>>size;
		sharks.push_back(shark(r,c,speed,dir,size));
		map[r][c].push_back(i);
	}
	
	for(int c=1;c<=COL;c++){		
		Fisher();
		Catch();
		Swim();
		Arrange();
	}
	cout<<total<<endl;
	return 0;
}
