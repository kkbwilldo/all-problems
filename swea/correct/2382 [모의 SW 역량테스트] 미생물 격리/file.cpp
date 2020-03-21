/*
미생물 군집 구조체(위치,방향,미생물 수,살아있음)를 만들어 사용.

벡터 map[MAX][MAX]은 미생물 군집의 인덱스를 저장하는 배열로 한 장소에 여러 군집이 있을 수 
있으므로 벡터를 사용하여 인덱스를 저장.

벡터 clusters는 군집 정보를 담는 배열. 

주어진 시간동안 move(),arrange()로 시뮬레이션 진행.

move()는 1. map 전체 클리어 2. 살아있는 군집 대상으로 3. 각자의 방향으로 이동 4. 이동 후 좌표 map에 푸쉬

arrange()는 
1. 테두리에 있는 군집의 이동 방향 업데이트, 미생물 수 절반, 미생물 수 0이면 죽음 표시 
2. map에서 한 장소에 여러 인덱스 있는 경우를 찾아, 가장 많은 미생물 수를 가지고 있는 인덱스를 찾고, 해당 클러스터 인덱스의 미생물 수에 모든 미생물 수를 더한다. 그리고 맵에서 가장 큰 인덱스만 남기고 나머지 인덱스 삭제

*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // 이거 틀림;; 런타임 에러 이유

// 미생물 군집 구조체 
struct cluster{
	int x,y;
	int dir;
	int cnt;
	int live;
	// 생성자 
	cluster(int _x,int _y,int _cnt,int _dir) : x(_x), y(_y), cnt(_cnt), dir(_dir), live(true){}
};

int testcase,size,due,numClusters;
int x,y,cnt,dir;
int dx[]={0,-1,1,0,0}; // 제자리,상,하,좌,우
int dy[]={0,0,0,-1,1};
vector <int> map[MAX][MAX]; // 군집 인덱스 담을 맵
vector <cluster> clusters;  // 군집 정보 배열 

// 군집 이동
void move(){
	for(int i=0;i<numClusters;i++){
		int x = clusters[i].x;
		int y = clusters[i].y;
		map[x][y].clear(); // 이동 전 장소에서 군집 지우기 
	}
	for(int i=0;i<numClusters;i++){
		if(!clusters[i].live) continue;
		clusters[i].x += dx[clusters[i].dir]; // dir이라고 써서 틀림
		clusters[i].y += dy[clusters[i].dir];
		map[clusters[i].x][clusters[i].y].push_back(i); // 이동 후 장소 맵에 저장
	}
}

void arrange(){
	// 테두리에 있는 군집
	for(int i=0;i<numClusters;i++){
		if(!clusters[i].live) continue;
		int x = clusters[i].x;
		int y = clusters[i].y;
		if(x==0||x==size-1||y==0||y==size-1){
			if(clusters[i].dir%2==0) clusters[i].dir -= 1;
			else clusters[i].dir += 1;
			clusters[i].cnt /= 2; // 여기 틀림
		}
		if(!clusters[i].cnt) clusters[i].live = false;
	}
	// 같은 장소에 있는 군집 정리 
	for(int i=0;i<numClusters;i++){
		if(!clusters[i].live) continue;
		int x = clusters[i].x;
		int y = clusters[i].y;
		if(map[x][y].size()>1){ // 같은 장소에 여러 군집 
			int maxIdx = -1;
			int maxVal = 0;
			int sum = 0;
			for(int j=0;j<map[x][y].size();j++){
				int idx = map[x][y][j]; // 군집 인덱스 
				sum += clusters[idx].cnt;
				if(maxVal<clusters[idx].cnt){
					maxVal = clusters[idx].cnt;
					maxIdx = idx;
				}
			}
			clusters[maxIdx].cnt = sum;
			for(int j=0;j<map[x][y].size();j++){
				int idx = map[x][y][j];
				if(idx != maxIdx) clusters[idx].live = false;
			}
			map[x][y].clear();
			map[x][y].push_back(maxIdx);
		}
	}
}

int sumUp(){
	int sum = 0;
	for(int i=0;i<numClusters;i++){
		if(clusters[i].live) sum+=clusters[i].cnt;
	}
	return sum;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
	
		clusters.clear();
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				map[i][j].clear();
			}
		}
		
		cin>>size>>due>>numClusters;
		for(int i=0;i<numClusters;i++){
			cin>>x>>y>>cnt>>dir;
			clusters.push_back(cluster(x,y,cnt,dir));
		}
		
		for(int i=0;i<due;i++){
			move();
			arrange();
		}
		
		cnt = sumUp();
		cout<<"#"<<test<<" "<<cnt<<endl;
	}
	return 0;
}


