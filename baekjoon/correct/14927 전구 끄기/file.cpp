#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;
const int INF=987987987;

int size,minVal,numClicks;
int indice[MAX];
int dr[]={0,-1,1,0,0};
int dc[]={0,0,0,-1,1};
int temp[MAX][MAX];
int map[MAX][MAX];
bool allOff;

void Click(int r,int c){
	for(int i=0;i<5;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0||nr>=size||nc<0||nc>=size) continue;
		map[nr][nc]^=1;
	}
	numClicks++;
}

void ClickRest(){
	for(int r=1;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r-1][c]==0) continue;
			Click(r,c);
		}
	}
}

void CheckOffs(){
	allOff=true;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]==1){
				allOff=false;
				return;
			}
		}
	}
}

void Copy(int temp[][MAX],int map[][MAX]){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			temp[r][c]=map[r][c];
		}
	}
}

void AllCases(int depth){
	if(depth==size){
		Copy(temp,map);
		numClicks=0;
		for(int i=0;i<size;i++){
			if(indice[i]) Click(0,i);
		}
		ClickRest();
		CheckOffs();
		if(allOff) minVal=min(minVal,numClicks);
		Copy(map,temp);
		return;
	}
	indice[depth]=1;
	AllCases(depth+1);
	indice[depth]=0;
	AllCases(depth+1);
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
		}
	}
	
	minVal=INF;
	AllCases(0);
	if(minVal==INF) minVal=-1;
	cout<<minVal<<endl;
	
	return 0;
}
