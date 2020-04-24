#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX = 20;
const int INF = 987987987;

int testcase,minVal;
int numBombs,COL,ROW;
int selected[MAX];
int map[MAX][MAX],temp[MAX][MAX];


bool isOff;

void Print(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<map[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void InitMap(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			map[r][c]=temp[r][c];
		}
	}
}

void ChainBomb(int StartR,int StartC,int bombSize){
	queue <tuple<int,int,int> > q;
	q.push(make_tuple(StartR,StartC,bombSize));
	map[StartR][StartC]=0;
	while(!q.empty()){
		int r,c,size;
		tie(r,c,size)=q.front();
		q.pop();
		for(int nr=r-1;nr>=r-(size-1);nr--){ //r이 아니라 nr이다 빡대가리야		
			if(nr<0||nr>=ROW) break;
			if(map[nr][c]==0) continue;
			map[nr][c]=0;
			q.push(make_tuple(nr,c,map[nr][c]));
		}
		for(int nr=r+1;nr<=r+(size-1);nr++){
			if(nr<0||nr>=ROW) break;
			if(map[nr][c]==0) continue;
			map[nr][c]=0;
			q.push(make_tuple(nr,c,map[nr][c]));
		}
		for(int nc=c-1;nc>=c-(size-1);nc--){
			if(nc<0||nc>=COL) break;
			if(map[r][nc]==0) continue;
			map[r][nc]=0;
			q.push(make_tuple(r,nc,map[r][nc]));
		}
		for(int nc=c+1;nc<=c+(size-1);nc++){
			if(nc<0||nc>=COL) break;
			if(map[r][nc]==0) continue;
			map[r][nc]=0;
			q.push(make_tuple(r,nc,map[r][nc]));
		}
	}
}

void PullDown(){
	for(int c=0;c<COL;c++){
		for(int r=ROW-2;r>=0;r--){
			if(map[r][c]==0) continue;
			int tmp=r+1;
			while(tmp<ROW){
				if(map[tmp][c]!=0) break;
				tmp++;
			}
			tmp--;
			map[tmp][c]=map[r][c];
			map[r][c]=0;
		}
	}
}

int NumBricks(){
	int cnt=0;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(map[r][c]!=0) cnt++;
		}
	}
	return cnt;
}

int FindRow(int c){
	for(int r=0;r<ROW;r++){
		if(map[r][c]!=0) return r;
	}
	return -1;
}

void DropBombs(int depth){
	if(isOff) return;
	if(depth==numBombs){
		InitMap();
		for(int i=0;i<numBombs;i++){
			int c=selected[i];
			int r=FindRow(c);
			if(r==-1) return;
			ChainBomb(r,c,map[r][c]);
			PullDown();
		}
		isOff=true;
		minVal=min(minVal,NumBricks());
		Print();
		return;
	}
	for(int i=0;i<COL;i++){
		selected[depth]=i;
		DropBombs(depth+1);
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(map,0,sizeof(map));
		memset(temp,0,sizeof(temp));
		minVal=INF;
		cin>>numBombs>>COL>>ROW;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>map[r][c];
				temp[r][c]=map[r][c];
			}
		}
		cout<<numBombs<<endl;
		Print();
		DropBombs(0);
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
