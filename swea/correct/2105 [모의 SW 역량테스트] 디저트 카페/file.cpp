// [모의 SW 역량테스트] 디저트 카페
#include <iostream>
#include <cstring>
using namespace std;

const int MAP = 25;
const int DESSERT = 105;

struct point{
	int r,c;
	point() : r(0), c(0) {}
	point(int _r,int _c) : r(_r), c(_c) {}
};

int testcase, size;
int maxVal;
int map[MAP][MAP];
int dessert[DESSERT];
point Top,Left,Right,Bottom;

bool hasRepeated(){
	for(int temp=0;temp<DESSERT;temp++){ // 중복 확인
		if(dessert[temp]>1){
			return true;
		}
	}
	return false;
}

bool findBottom(){
	int n = ((Right.r+Right.c)-(Left.r+Left.c))/2;
	Bottom.r = Left.r + n;
	Bottom.c = Left.c + n;
	if(Bottom.r<0||Bottom.r>=size||Bottom.c<0||Bottom.c>=size) return false;
	return true;
}

void goLow(point start,string dir, int rng){

	int r = start.r;
	int c = start.c;
	if(dir == "GO_LEFT"){
		for(int i=0;i<rng-1;i++){
			r++;c--;
			int idx = map[r][c];
			dessert[idx]++;
		}
	}
	else if(dir == "GO_RIGHT"){
		for(int i=0;i<rng-1;i++){
			r++;c++;
			int idx = map[r][c];
			dessert[idx]++;
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(map,0,sizeof(map));
		maxVal = 0;
		
		cin>>size;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cin>>map[i][j];
			}
		}
		// Top 탐색 
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				
				Top=point(i,j);
				// 좌,우 뻗을 수 있는 거리 
				int distL = Top.c; 
				int distR = (size-1) - Top.c;
				// Left 탐색
				Left=point(Top.r,Top.c);
				for(int l=0;l<distL;l++){
					Left.r++;Left.c--;
					// Right 탐색
					Right=point(Top.r,Top.c);
					Bottom=point();
					for(int r=0;r<distR;r++){
						Right.r++;Right.c++;
						if(!findBottom()) break;
						// T,L,R,B 선택 완료
						
						// 중복 검사 
						memset(dessert,0,sizeof(dessert));
						
						dessert[map[Top.r][Top.c]]++;
						dessert[map[Left.r][Left.c]]++;
						dessert[map[Right.r][Right.c]]++;
						dessert[map[Bottom.r][Bottom.c]]++;
						if(dessert[map[Top.r][Top.c]]>1) break;
						if(dessert[map[Left.r][Left.c]]>1) break;
						if(dessert[map[Right.r][Right.c]]>1) break;
						if(dessert[map[Bottom.r][Bottom.c]]>1) break;					
					
						goLow(Top,"GO_LEFT",Left.r-Top.r); // Top -> Left
						goLow(Top,"GO_RIGHT",Right.r-Top.r); // Top -> Right				
						goLow(Left,"GO_RIGHT",Bottom.r-Left.r); // Left -> Bottom
						goLow(Right,"GO_LEFT",Bottom.r-Right.r); // Right -> Bottom
						if(hasRepeated()) continue; // 중복 확인
						// 디저트 개수 세기
						int cnt=0;
						for(int h=0;h<DESSERT;h++){
							if(dessert[h]==1) cnt++;
						}
						if(maxVal<cnt) maxVal=cnt;
					}
				}
			}
		}
		if(maxVal) cout<<"#"<<test<<" "<<maxVal<<endl;
		else cout<<"#"<<test<<" "<<-1<<endl;
	}
	return 0;
}
