#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX = 12;
const int SIZE = 9;

int dr[]={-1,-1,-1,0,0,0,1,1,1};
int dc[]={-1,0,1,-1,0,1,-1,0,1};
int map[MAX][MAX];
bool visited[SIZE+1];

vector <pair<int,int> > slot;

void Print(){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool upDownOk(int r,int c){
	memset(visited,0,sizeof(visited));
	for(int i=0;i<SIZE;i++){
		int num = map[i][c];
		if(!num) continue;
		if(visited[num]) return false;
		visited[num]=true;
	}
	return true;
}

bool leftRightOk(int r,int c){
	memset(visited,0,sizeof(visited));
	for(int i=0;i<SIZE;i++){
		int num = map[r][i];
		if(!num) continue;
		if(visited[num]) return false;
		visited[num]=true;
	}
	return true;
}

bool cellOk(int r,int c){
	memset(visited,0,sizeof(visited));
	int centerR=r/3;
	int centerC=c/3;
	centerR=centerR*3+1;
	centerC=centerC*3+1;
	for(int i=0;i<SIZE;i++){
		int nr=centerR+dr[i];
		int nc=centerC+dc[i];
		int num = map[nr][nc];
		if(!num) continue;
		if(visited[num]) return false;
		visited[num]=true;
	}
	return true;
}

void fillIn(int depth){
	if(depth==slot.size()){
		Print();
		exit(0);
	}
	for(int digit=1;digit<=SIZE;digit++){
		int r=slot[depth].first;
		int c=slot[depth].second;
		map[r][c]=digit;
		if(upDownOk(r,c)&&leftRightOk(r,c)&&cellOk(r,c)) fillIn(depth+1);
		map[r][c]=0;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int r=0;r<SIZE;r++){
		for(int c=0;c<SIZE;c++){
			cin>>map[r][c];
			if(map[r][c]==0) slot.push_back(make_pair(r,c));
		}
	}
	fillIn(0);
	return 0;
}
