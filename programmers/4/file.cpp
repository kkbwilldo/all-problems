#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
 
int solution(vector<vector<int>> board) {

	const int INF=987987987;
	int answer = INF;
	int size = board.size();
	int dr[]={-1,1,0,0};
	int dc[]={0,0,-1,1};
	int dists[4][30][30];

	for(int dir=0;dir<4;dir++){
	   for(int r=0;r<size;r++){
		   for(int c=0;c<size;c++){
				dists[dir][r][c]=INF;
			}
		}
	}

	queue <tuple<int,int,int,int>> q;
	for (int i=0;i<4;i++){
		q.push(make_tuple(0,0,i,0));
		dists[i][0][0]=0;
	}

	while (!q.empty()){
		int r,c,dir,dist;
		tie(r,c,dir,dist)=q.front();
		q.pop(); 
		if(r==size-1&&c==size-1){
			answer=min(answer,dist);
			continue;
		}
		for (int i=dir;i<dir+4;i++) {
			int ndir=i%4;
			int nr=r+dr[ndir];
			int nc=c+dc[ndir];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(ndir==dir){
				if(dists[ndir][nr][nc]>dist+100 && board[nr][nc]==0){
					dists[ndir][nr][nc]=dist+100;
					q.push(make_tuple(nr,nc,ndir,dist+100));
				}
			}
			else{
				if(dists[ndir][nr][nc]>dist+600 && board[nr][nc]==0){
					dists[ndir][nr][nc]=dist+600;
					q.push(make_tuple(nr,nc,ndir,dist+600));
				}
			}
		}
	}
	return answer;
}
 


