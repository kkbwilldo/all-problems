#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int SIZE=5;
const int INF=987987987;

int answer;
int dr[]={-1,1,0,0,0,0};
int dc[]={0,0,-1,1,0,0};
int dh[]={0,0,0,0,-1,1};
int board[SIZE][SIZE][SIZE];
int temp[SIZE][SIZE][SIZE];

void Copy(int (&temp)[][SIZE][SIZE], int (&origin)[][SIZE][SIZE]){
	for(int h=0;h<SIZE;h++){
		for(int r=0;r<SIZE;r++){
			for(int c=0;c<SIZE;c++){
				temp[h][r][c]=origin[h][r][c];
			}
		}
	}
}

void Clockwise(int plate, int (&origin)[][SIZE][SIZE]){
	int temp[SIZE][SIZE];
	for(int r=0;r<SIZE;r++){
		for(int c=0;c<SIZE;c++){
			temp[r][c]=origin[plate][r][c];
		}
	}
	for(int r=0;r<SIZE;r++){
		for(int c=0;c<SIZE;c++){
			origin[plate][c][SIZE-1-r]=temp[r][c];
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	answer=INF;
	
	for(int h=0;h<SIZE;h++){
		for(int r=0;r<SIZE;r++){
			for(int c=0;c<SIZE;c++){
				cin>>board[h][r][c];
			}
		}
	}
	
	// 2초: 2*10^8=200,000,000
	// 전체 경우의 수: 4^5*5!*8=1024개*120개*8개=983,040개
	
	for(int first=0;first<4;first++){
		Copy(temp,board);
		Clockwise(0,temp);
		for(int second=0;second<4;second++){
			Clockwise(1,temp);
			for(int third=0;third<4;third++){
				Clockwise(2,temp);
				for(int forth=0;forth<4;forth++){
					Clockwise(3,temp);
					for(int fifth=0;fifth<4;fifth++){
						Clockwise(4,temp);
						Stack();
						for(int i=0;i<8;i++){
							BFS();
						}
					}
				}
			}
		}
	}
	
	return 0;
}
