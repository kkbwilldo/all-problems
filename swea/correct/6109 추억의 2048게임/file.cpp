/*
100개 테스트케이스 1초, N=20 -> N^5가능

오른쪽으로 이동 GoRight(), 이동 후 맵 정리 Move(), 맵을 시계방향 90도 회전 Rot(),
방향에 따라 회전 Rotate(), 역방향 회전 Reverse()로 모듈화하여 시뮬레이션 진행

right인 경우는 회전시키지 않고 오른쪽으로 이동시킴
up인 경우는 1번 회전후 오른쪽 이동시키고 다시 역회전
left인 경우는 2번, down인 경우는 3번 회전시킨다


*/
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX = 22;

int testcase,size,rot;
string dir;
int map[MAX][MAX];

void Rot(){
	int temp[MAX][MAX];
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
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
	for(int r=0;r<=size-1;r++){
		for(int c=size-2;c>=0;c--){
			int cur=c;
			while(cur<size-1){
				if(map[r][cur+1]==0){
					map[r][cur+1]=map[r][cur];
					map[r][cur]=0;
					cur++;
				}
				else break;
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

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>dir;
		rot=0;
		if(dir=="up") rot=1;
		else if(dir=="left") rot=2;
		else if(dir=="down") rot=3;
		memset(map,0,sizeof(map));
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>map[r][c];
			}
		}
		Rotate(rot);
		Move();
		Reverse(rot);
		cout<<"#"<<test<<endl;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cout<<map[r][c]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
