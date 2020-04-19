#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

const int MAX = 20;
const int INF = 987987987;

int testcase,minVal;
int numBombs,width,height;
int selected[MAX];
int map[MAX][MAX],temp[MAX][MAX];

void Print(){
	for(int r=0;r<height;r++){
		for(int c=0;c<width;c++){
			cout<<map[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void ChainBomb(int StartR,int StartC,int bombSize){
	queue <tuple<int,int,int> > q;
	q.push(make_tuple(StartR,StartC,bombSize));
	while(!q.empty()){
		int r,c,size;
		tie(r,c,size)=q.front();
		q.pop();
		map[r][c]=0;
		for(int nr=r-1;nr>=r-(size-1);r--){
			if(nr<0||nr>=height) break;
			if(map[nr][c]==0) continue;
			q.push(make_tuple(nr,c,map[nr][c]));
			map[nr][c]=0;
		}
		for(int nr=r+1;nr<=r+(size-1);r++){
			if(nr<0||nr>=height) break;
			if(map[nr][c]==0) continue;
			q.push(make_tuple(nr,c,map[nr][c]));
			map[nr][c]=0;
		}
		for(int nc=c-1;nc>=c-(size-1);c--){
			if(nc<0||nc>=width) break;
			if(map[r][nc]==0) continue;
			q.push(make_tuple(r,nc,map[r][nc]));
			map[r][nc]=0;
		}
		for(int nc=c+1;nc<=c+(size-1);c++){
			if(nc<0||nc>=width) break;
			if(map[r][nc]==0) continue;
			q.push(make_tuple(r,nc,map[r][nc]));
			map[r][nc]=0;
		}
	}
}

void PullDown(){
	for(int c=0;c<width;c++){
		for(int r=height-2;r>=0;r--){
			if(map[r][c]==0) continue;
			int tmp=r;
			while(tmp<height){
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
	for(int r=0;r<height;r++){
		for(int c=0;c<width;c++){
			if(map[r][c]!=0) cnt++;
		}
	}
	return cnt;
}

int FindRow(int c){
	for(int r=0;r<height;r++){
		if(map[r][c]!=0) return r;
	}
	return -1;
}

void DropBombs(int depth){
	if(depth==numBombs){
		bool isValid=true;
		for(int r=0;r<height;r++){
			for(int c=0;c<width;c++){
				map[r][c]=temp[r][c];
			}
		}
		Print();
		for(int i=0;i<numBombs;i++){
			int c=selected[i];
			int r=FindRow(c);
			if(r==-1){
				isValid=false;
				break;
			}
			ChainBomb(r,c,map[r][c]);
			Print();
			PullDown();
			Print();
		}
		if(isValid){
			int result=NumBricks();
			minVal=min(minVal,result);
		}
		return;
	}
	for(int i=0;i<width;i++){
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
		cin>>numBombs>>width>>height;
		for(int r=0;r<height;r++){
			for(int c=0;c<width;c++){
				cin>>map[r][c];
				temp[r][c]=map[r][c];
			}
		}
		DropBombs(0);
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
