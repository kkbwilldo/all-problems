#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 22;

int size,maxVal,limit;
int map[MAX][MAX];

void BackUp(int tmp[][MAX],int origin[][MAX]){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			tmp[r][c]=origin[r][c];
		}
	}
}

void Rot(){
	int temp[MAX][MAX];
	for(int r=0;r<=size-1;r++){
		for(int c=0;c<=size-1;c++){
			temp[c][size-1-r]=map[r][c];
		}
	}
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			map[r][c]=temp[r][c];
		}
	}
}

void Rotate(int dir){
	if(dir==1){Rot();}
	else if(dir==2){Rot();Rot();}
	else if(dir==3){Rot();Rot();Rot();}
}

void Reverse(int dir){
	if(dir==3){Rot();}
	else if(dir==2){Rot();Rot();}
	else if(dir==1){Rot();Rot();Rot();}
}

void GoRight(){
	for(int r=0;r<size;r++){
		for(int c=size-2;c>=0;c--){
			int cur=c;
			while(cur<size-1){
				if(map[r][cur+1]!=0) break;
				map[r][cur+1]=map[r][cur];
				map[r][cur]=0;
				cur++;
			}
		}
	}
}

void Move(){
	GoRight();
	for(int r=0;r<size;r++){
		for(int c=size-1;c>=1;c--){
			if(map[r][c]==0) continue;
			if(map[r][c]==map[r][c-1]){
				map[r][c]*=2;
				map[r][c-1]=0;
			}
		}
	}
	GoRight();
}

int biggest(){
	int val=0;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			val=max(map[r][c],val);
		}
	}
	return val;
}

void Search(int depth){
	if(depth==limit){
		maxVal=max(biggest(),maxVal);
		return;
	}
	for(int i=0;i<4;i++){
		int temp[MAX][MAX];
		BackUp(temp,map);
		Rotate(i);
		Move();
		Reverse(i);
		Search(depth+1);
		BackUp(map,temp);
	}
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
	limit=5;maxVal=0;
	Search(0);
	cout<<maxVal<<endl;
	return 0;
}
