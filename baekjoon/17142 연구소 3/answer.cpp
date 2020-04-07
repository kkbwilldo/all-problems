#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 55;

int size,numPicks;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
int dists[MAX][MAX];

vector <pair<int,int> > candi;

int ans=-1;

void bfs(){
	memset(dists,-1,sizeof(dists));
	queue <pair<int,int> > q;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]==3){
				q.push(make_pair(r,c));
				dists[r][c]=0;
			}
		}
	}
	while(!q.empty()){
		int r,c;
		tie(r,c)=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(map[nr][nc]!=1&&dists[nr][nc]==-1){
				dists[nr][nc]=dists[r][c]+1;
				q.push(make_pair(nr,nc));
			}
		}
	}
	int cur=0;//max값
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]==0){
				if(dists[r][c]==-1) return;
				if(cur<dists[r][c]) cur=dists[r][c];
			}
		}
	}
	if(ans==-1||ans>cur) ans=cur;
}

void go(int idx,int cnt){
	if(idx==candi.size()){
		if(cnt==numPicks) bfs();
	}
	else{
		int r,c;
		tie(r,c)=candi[idx];
		map[r][c]=3;//활성화
		go(idx+1,cnt+1);
		map[r][c]=2;
		go(idx+1,cnt);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>numPicks;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>map[r][c];
			if(map[r][c]==2) candi.push_back(make_pair(r,c));
		}
	}
	go(0,0);
	cout<<ans<<endl;
	return 0;
}
