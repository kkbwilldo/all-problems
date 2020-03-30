// [S/W 문제해결 응용] 7일차 - 행렬 찾기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;

const int MAX = 100;

struct matrix{
	int row,col,areaSize;
};

int testcase,mapSize,area;
int row,col;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int map[MAX][MAX];
int label[MAX][MAX];
bool labelCheck[20];
bool visited[MAX][MAX];

bool cmp(const matrix &a, const matrix &b){
	if(a.areaSize<b.areaSize) return true;
	else if(a.areaSize==b.areaSize) return a.row<b.row;
	else return false;
}

void labelling(int x, int y){
	area++;
	visited[x][y]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		label[r][c]=area;
		for(int i=0;i<4;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(nr<0||nr>=mapSize||nc<0||nc>=mapSize) continue; // 부등호 잘못씀
			if(map[nr][nc]!=0&&!visited[nr][nc]){
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);

	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(map,0,sizeof(map));
		memset(label,0,sizeof(label));
		memset(labelCheck,0,sizeof(labelCheck));
		memset(visited,0,sizeof(visited));
	
		cin>>mapSize;
		for(int i=0;i<mapSize;i++){
			for(int j=0;j<mapSize;j++){
				cin>>map[i][j];
			}
		}
			
		area=0;
		for(int i=0;i<mapSize;i++){
			for(int j=0;j<mapSize;j++){
				if(map[i][j]!=0&&!visited[i][j]) {
					labelling(i,j);
				}
			}
		}
		
		int END = area;  // 잘못 잡음
		
		vector <matrix> matrice(END);
		
		for(int i=0;i<mapSize;i++){
			for(int j=0;j<mapSize;j++){
				if(label[i][j]!=0){
					int idx = label[i][j]-1;
					if(labelCheck[idx]) continue;
					labelCheck[idx]=true;
					row=col=0;
					
					for(int h=0;h<mapSize;h++){
						if(i+h>=mapSize) break;
						if(label[i+h][j]!=idx+1) break;
						row++;
					}
					for(int h=0;h<mapSize;h++){
						if(j+h>=mapSize) break;
						if(label[i][j+h]!=idx+1) break;
						col++;
					}
					
					matrice[idx].row=row;
					matrice[idx].col=col;
					matrice[idx].areaSize=row*col;
				}
			}	
		}
		
		sort(matrice.begin(),matrice.end(),cmp);
		cout<<"#"<<test<<" "<<END<<" "; // 문제 잘못이해해서 출력을 잘못함
		for(int i=0;i<END;i++){
			cout<<matrice[i].row<<" "<<matrice[i].col<<" ";
		}
		cout<<endl;
		
	}
	
	return 0;
}
