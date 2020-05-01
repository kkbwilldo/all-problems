#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX=55;

int ROW,COL,TIME;
int sum;
int Side,cnt;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX],sideMap[MAX][MAX];

vector <int> filter;

void init(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>map[r][c];
			if(map[r][c]==-1) filter.push_back(r);
		}
	}
}

void Print(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]==-1) cout<<'X'<<" ";
			else cout<<map[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void Spread(){
	memset(sideMap,0,sizeof(sideMap));
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]<=0) continue;
			Side=map[r][c]/5;
			cnt=0;
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
				if(map[nr][nc]==-1) continue;
				sideMap[nr][nc]+=Side;
				cnt++;
			}
			map[r][c]-=cnt*Side;
		}
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			map[r][c]+=sideMap[r][c];
		}
	}
}

void Run(){
	int first=filter[0];
	int second=filter[1];
	// 상단 필터 
	for(int r=first-2;r>=0;r--) map[r+1][0]=map[r][0];
	for(int c=1;c<=COL-1;c++) map[0][c-1]=map[0][c];
	for(int r=1;r<=first;r++) map[r-1][COL-1]=map[r][COL-1];
	for(int c=COL-1;c>=2;c--) map[first][c]=map[first][c-1];
	map[first][1]=0;
	// 하단 필터
	for(int r=second+2;r<=ROW-1;r++) map[r-1][0]=map[r][0];
	for(int c=1;c<=COL-1;c++) map[ROW-1][c-1]=map[ROW-1][c];
	for(int r=ROW-2;r>=second;r--) map[r+1][COL-1]=map[r][COL-1];
	for(int c=COL-2;c>=1;c--) map[second][c+1]=map[second][c];
	map[second][1]=0;
}

void SumUp(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]!=-1) sum+=map[r][c];
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>TIME;
	init();
	//Print();
	for(int i=0;i<TIME;i++){
		Spread();
		//Print();
		Run();
		//Print();
	}
	SumUp();
	
	cout<<sum<<endl;
	return 0;
}




