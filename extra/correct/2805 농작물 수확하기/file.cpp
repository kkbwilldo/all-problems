#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX = 60;

int testcase,size,profit;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX];

void Print(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cout<<visited[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;	
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		memset(visited,0,sizeof(visited));
		profit=0;
		cin>>size;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				char temp;
				cin>>temp;
				board[r][c]=temp-'0';
			}
		}
		int StartR=size/2;
		int StartC=size/2;
		visited[StartR][StartC]=true;
		queue <tuple<int,int,int> > q;
		q.push(make_tuple(StartR,StartC,size/2));
		while(!q.empty()){
			int r,c,dist;
			tie(r,c,dist)=q.front();
			q.pop();
			profit+=board[r][c];
			if(dist<=0) continue;
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=size||nc<0||nc>=size) continue;
				if(visited[nr][nc]) continue;
				visited[nr][nc]=true;
				q.push(make_tuple(nr,nc,dist-1));
			}
		}
		//Print();
		cout<<"#"<<test<<" "<<profit<<endl;
	}
	return 0;
}
