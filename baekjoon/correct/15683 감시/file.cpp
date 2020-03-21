#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX=10;
const int INF=987987987;

struct item{
	int r,c,type;
	item(int _r,int _c,int _type):r(_r),c(_c),type(_type){}
};

int ROW,COL,minVal;
int map[MAX][MAX];

vector <item> CCTV;

void CheckSafeZone(){
	int cnt=0;
	for(int r=1;r<=ROW;r++){
		for(int c=1;c<=COL;c++){
			if(map[r][c]==0) cnt++;
		}
	}
	minVal=min(minVal,cnt);
}

void Go(int dir,int r,int c){
	int nr=r;
	int nc=c;
	if(dir==0){ // 상
		while(1){
			nr--;
			if(nr<1||nr>ROW||nc<1||nc>COL) break;
			if(map[nr][nc]==6) break;
			if(1<=map[nr][nc]&&map[nr][nc]<=5) continue;
			map[nr][nc]=-1;
		}
	}
	else if(dir==1){ // 우
		while(1){
			nc++;
			if(nr<1||nr>ROW||nc<1||nc>COL) break;
			if(map[nr][nc]==6) break;
			if(1<=map[nr][nc]&&map[nr][nc]<=5) continue;
			map[nr][nc]=-1;
		}
	}
	else if(dir==2){ // 하
		while(1){
			nr++;
			if(nr<1||nr>ROW||nc<1||nc>COL) break;
			if(map[nr][nc]==6) break;
			if(1<=map[nr][nc]&&map[nr][nc]<=5) continue;
			map[nr][nc]=-1;
		}
	}
	else if(dir==3){ // 좌
		while(1){
			nc--;
			if(nr<1||nr>ROW||nc<1||nc>COL) break;
			if(map[nr][nc]==6) break;
			if(1<=map[nr][nc]&&map[nr][nc]<=5) continue;
			map[nr][nc]=-1;
		}
	}
}

void Copy(int temp[][MAX],int map[][MAX]){
	for(int r=1;r<=ROW;r++){
		for(int c=1;c<=COL;c++){
			temp[r][c]=map[r][c];
		}
	}
}

void Watch(int depth){
	if(depth==CCTV.size()){
		CheckSafeZone();
		return;
	}
	int Type=CCTV[depth].type;
	int r=CCTV[depth].r;
	int c=CCTV[depth].c;
	if(Type==1){
		for(int i=0;i<4;i++){
			int temp[MAX][MAX];
			memset(temp,0,sizeof(temp));
			Copy(temp,map);
			Go(i,r,c);
			Watch(depth+1);
			Copy(map,temp);
		}
	}
	else if(Type==2){
		for(int i=0;i<2;i++){
			int temp[MAX][MAX];
			memset(temp,0,sizeof(temp));
			Copy(temp,map);
			Go(i,r,c);
			Go(i+2,r,c);
			Watch(depth+1);
			Copy(map,temp);
		}
	}
	else if(Type==3){
		for(int i=0;i<4;i++){
			int temp[MAX][MAX];
			memset(temp,0,sizeof(temp));
			Copy(temp,map);
			Go(i,r,c);
			Go((i+1)%4,r,c);
			Watch(depth+1);
			Copy(map,temp);
		}
	}
	else if(Type==4){
		for(int i=0;i<4;i++){
			int temp[MAX][MAX];
			memset(temp,0,sizeof(temp));
			Copy(temp,map);
			Go((i+3)%4,r,c);
			Go(i,r,c);
			Go((i+1)%4,r,c);
			Watch(depth+1);
			Copy(map,temp);
		}
	}
	else if(Type==5){
		int temp[MAX][MAX];
		memset(temp,0,sizeof(temp));
		for(int i=0;i<4;i++){
			Go(i,r,c);
		}
		Watch(depth+1);
		Copy(map,temp);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	minVal=INF;
	for(int r=1;r<=ROW;r++){
		for(int c=1;c<=COL;c++){
			cin>>map[r][c];
			if(1<=map[r][c]&&map[r][c]<=5) 
				CCTV.push_back(item(r,c,map[r][c]));
		}
	}
	Watch(0);
	
	cout<<minVal<<endl;
	return 0;
}

