/*
1. 전체 탐색으로 시작점 Top을 검색
2. Top을 기준으로 좌우로 뻗을 수 있는 거리 계산
3. 좌우로 뻗을 수 있는 거리가 모두 1이상이 아니면 다음 Top 검색
4. 2중 for loop으로 Left,Right 탐색
5. Left, Right로 Bottom 좌표 계산
6. Bottom 좌표가 맵 밖이면 다음 Right 검색
7. Top,Left,Right,Bottom을 잇는 경계선을 visited로 방문 처리
8. 2차원 배열 label을 모두 5로 초기화
9. 1,2,3,4 구역을 경계선을 이용하여 label 표기
10. 2중 for loop으로 1,2,3,4,5 구역의 인원수 map[r][c]를 1차원 배열 population[5]에 더함
11. population을 정렬한 후 최대값-최소값 계산
12. minVal을 업데이트 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX = 22;
const int INF = 987987987;

int size,minVal;
int reachL,reachR;
int tempR,tempC;
int population[5];
int map[MAX][MAX];
int label[MAX][MAX];
bool visited[MAX][MAX];

struct point {
	int r,c;
	point():r(-1),c(-1){}
	point(int _r,int _c) : r(_r),c(_c){}	
};

point Top,Left,Right,Bottom;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	// 입력
	cin>>size;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cin>>map[i][j];
		}
	}
	minVal=INF;
	// Top 탐색 
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			Top = point(r,c);
			// 좌우 뻗을 수 있는 거리 계산
			reachL=Top.c;reachR=size-1-Top.c;
			if(reachL==0||reachR==0) continue;
			// Left 탐색 
			Left=point(Top.r,Top.c);
			for(int i=0;i<reachL;i++){
				Left.r++;Left.c--;
				// Right 탐색 
				Right=point(Top.r,Top.c);
				for(int j=0;j<reachR;j++){
					Right.r++;Right.c++;
					// Bottom 좌표 계산
					int n=((Right.r+Right.c)-(Left.r+Left.c))/2;
					Bottom=point(Left.r+n,Left.c+n);
					if(Bottom.r<0||Bottom.r>=size||Bottom.c<0||Bottom.c>=size) 
						break;
					// label 5로 초기화 
					for(int x=0;x<size;x++){
						for(int y=0;y<size;y++){
							label[x][y]=5;
						}
					}
					// 초기화 
					memset(visited,0,sizeof(visited));
					memset(population,0,sizeof(population));
					visited[Top.r][Top.c]=true;
					// Top -> Left 경계선 
					tempR=Top.r;tempC=Top.c;		
					for(int h=0;h<Left.r-Top.r;h++){
						tempR++;tempC--;
						visited[tempR][tempC]=true;
					}
					// Top -> Right 경계선
					tempR=Top.r;tempC=Top.c;					
					for(int h=0;h<Right.r-Top.r;h++){
						tempR++;tempC++;
						visited[tempR][tempC]=true;
					}
					// Left -> Bottom 경계선 
					tempR=Left.r;tempC=Left.c;
					while(tempR<Bottom.r){
						tempR++;tempC++;
						visited[tempR][tempC]=true;
					}
					// Right -> Bottom 경계선 
					tempR=Right.r;tempC=Right.c;
					while(tempR<Bottom.r-1){
						tempR++;tempC--;
						visited[tempR][tempC]=true;
					}
					
					// 1 구역
					for(int x=0;x<Left.r;x++){
						for(int y=0;y<=Top.c;y++){
							if(visited[x][y]) break;
							label[x][y]=1;
						}
					}
					// 2 구역
					for(int x=0;x<=Right.r;x++){
						for(int y=size-1;y>Top.c;y--){
							if(visited[x][y]) break;
							label[x][y]=2;
						}
					}
					// 3 구역
					for(int x=Left.r;x<size;x++){
						for(int y=0;y<Bottom.c;y++){
							if(visited[x][y]) break;
							label[x][y]=3;
						}
					}
					// 4 구역
					for(int x=Right.r+1;x<size;x++){
						for(int y=size-1;y>=Bottom.c;y--){
							if(visited[x][y]) break;
							label[x][y]=4;
						}
					}
					// label을 인덱스로 하여 맵의 값을 population에 더함
					for(int x=0;x<size;x++){
						for(int y=0;y<size;y++){
							population[label[x][y]-1]+=map[x][y];
						}
					}
					/*
					for(int x=0;x<size;x++){
						for(int y=0;y<size;y++){
							cout<<label[x][y]<<" ";
						}cout<<endl;
					}cout<<endl;
					*/
					sort(population,population+5);
					minVal=min(minVal,population[4]-population[0]);
				}
			}
		}
	}
	cout<<minVal<<endl;
	return 0;
}
