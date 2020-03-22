/*
addFood는 매년 뿌려줄 양분의 양
foodMap은 현재 양분의 양
treeMap은 위치에 따른 나무의 인덱스 번호
trees는 나무 정보

spring(), summer(), fall(), winter()로 모듈화하여 문제 해결

spring(): 
전체 탐색으로 treeMap을 탐색. 
나무가 있는 위치를 찾고, 한 위치에 나무가 2개 이상이면 나무를 나이를 기준으로 오름차순 정렬.
treeMap에 있는 모든 나무들에 대해, 현 위치의 양분과 각 나무의 나이를 비교 후 
양분의 양과 나무의 나이, 죽음 여부를 업데이트

summer():
treeMap에서 죽어있는 나무 탐색 후 양분 맵 업데이트
treeMap 전부 clear
treeMap에 살아있는 나무의 인덱스 푸쉬

fall():
trees에서 살아있고 나이가 5배수인 나무 탐색
8방향으로 뻗어가면서 새로운 나무 심기

winter():
foodMap에 addFood 값 추가 

*/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 12;

struct tree{
	int r,c;
	int year;
	int idx;
	bool live;
	tree():r(-1),c(-1),year(-1),idx(-1),live(true){}
	tree(int _r,int _c, int _year,int _idx):r(_r),c(_c),year(_year),idx(_idx),live(true){}
};

int size,numTrees,numYears;
int x,y,YEAR;
int answer;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};
int addFood[MAX][MAX];
int foodMap[MAX][MAX];
vector <int> treeMap[MAX][MAX];
vector <tree> trees;

bool cmp(const int& a,const int& b){
	if(trees[a].year<trees[b].year) return true;
	return false;
}

void spring(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(treeMap[r][c].size()>0){
				if(treeMap[r][c].size()>1) 
					sort(treeMap[r][c].begin(),treeMap[r][c].end(),cmp);
				for(int i=0;i<treeMap[r][c].size();i++){
					int index = treeMap[r][c][i];
					if(trees[index].year>foodMap[r][c])
						trees[index].live=false;
					else{
						foodMap[r][c]-=trees[index].year;
						trees[index].year++;
					}
				}
			}
		}
	}
}

void summer(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			for(int i=0;i<treeMap[r][c].size();i++){
				int index = treeMap[r][c][i];
				if(trees[index].live==false) 
					foodMap[r][c]+=trees[index].year/2;
			}
		}
	}
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			treeMap[r][c].clear();
		}
	}
	for(int i=0;i<trees.size();i++){
		if(trees[i].live){
			int r = trees[i].r;
			int c = trees[i].c;
			int idx = trees[i].idx;
			treeMap[r][c].push_back(idx);
		}
	}
}

void fall(){ // N^2
	for(int i=0;i<trees.size();i++){
		if(trees[i].live && trees[i].year%5==0){
			int r=trees[i].r;
			int c=trees[i].c;
			for(int dir=0;dir<8;dir++){
				int nr=r+dr[dir];
				int nc=c+dc[dir];
				int idx=trees.size();
				int year=1;
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				trees.push_back(tree(nr,nc,year,idx));
				treeMap[nr][nc].push_back(idx);
			}
		}
	}
}

void winter(){ // N^2
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			foodMap[r][c]+=addFood[r][c];
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	// 입력
	cin>>size>>numTrees>>numYears;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>addFood[r][c];
		}
	}
	for(int i=0;i<numTrees;i++){
		cin>>x>>y>>YEAR;
		trees.push_back(tree(x-1,y-1,YEAR,i));
		treeMap[x][y].push_back(i);
	}
	// 양분맵 초기화 
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			foodMap[r][c]=5;
		}
	}
	// numYears 동안 계절 진행 
	for(int i=0;i<numYears;i++){
		spring();summer();fall();winter();
	}
	// 살아있는 나무 수 카운트 
	for(int i=0;i<trees.size();i++){
		if(trees[i].live) answer++;
	}
	
	cout<<answer<<endl;
	return 0;
}
