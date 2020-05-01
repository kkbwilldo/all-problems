#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 110;

int size,len;
int map[MAX][MAX],reflectedMap[MAX][MAX];
int answer;

void CountRoads(int map[][MAX]){
	for(int c=0;c<size;c++){
		int roadSize=1;
		bool noWay=false;
		for(int r=0;r<size-1;r++){
			int Cur=map[r][c];
			int Next=map[r+1][c];
			if(Cur==Next) roadSize++;
			else if(Cur==Next+1){
				for(int nr=r+1;nr<=r+len;nr++){
					if(nr>=size||map[nr][c]!=Next){
						noWay=true;
						break;
					}
				}
				if(noWay) break;
				r=r+len-1;
				roadSize=0;
			}
			else if(Cur+1==Next){
				if(roadSize<len){ // 여기 틀렸었음
					noWay=true;
					break;
				}
				roadSize=1;
			}
			else if(abs(Cur-Next)>=2){
				noWay=true;
				break;
			}
		}
		if(!noWay) answer++;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>len;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>map[r][c];
			reflectedMap[c][r]=map[r][c];
		}
	}
	CountRoads(map);
	CountRoads(reflectedMap);
	cout<<answer<<endl;
	return 0;
}
