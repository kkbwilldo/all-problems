#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 35;
const int INF = 987987987;

int numVerts,numHorzs,numBars;
int row,col;
int answer;
int barMap[MAX][MAX];
int visited[MAX][MAX];

bool ladderGame(){
	for(int c=1;c<=numVerts;c++){
		int curCol=c;
		for(int r=1;r<=numHorzs;r++){
			if(visited[r][curCol]) curCol++;
			else if(visited[r][curCol-1]) curCol--;
		}
		if(curCol!=c) return false;
	}
	return true;
}

void PutBars(int idx,int numBars){
	if(numBars>=4) return;
	if(ladderGame()==true){
		answer=min(answer,numBars);
		return;
	}
	for(int r=idx;r<=numHorzs;r++){
		for(int c=1;c<numVerts;c++){
			if(visited[r][c]) continue;
			if(visited[r][c-1]) continue;
			if(visited[r][c+1]) continue;
			visited[r][c]=true;
			PutBars(r,numBars+1);
			visited[r][c]=false;
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	answer=INF;
	cin>>numVerts>>numBars>>numHorzs;
	for(int i=0;i<numBars;i++){
		cin>>row>>col;
		visited[row][col]=true;
	}
	PutBars(1,0);
	if(answer==INF) answer=-1;
	cout<<answer<<endl;
	return 0;
}
