#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=100;
const int INF=987987987;

int testcase,minVal,answer;
int dr[]={0,0,1};
int dc[]={-1,1,0};
int board[MAX][MAX];
bool visited[MAX][MAX];

void GoDown(int col){
	queue <pair<int,int> > q;
	int StartR=0,StartC=col;
	visited[StartR][StartC]=true;
	q.push(make_pair(StartR,StartC));
	int cnt=0;
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		cnt++;
		if(r==MAX-1){
			if(minVal>cnt){
				minVal=cnt;
				answer=col;
			}
			break;
		}
		for(int i=0;i<3;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=MAX||nc<0||nc>=MAX) continue;
			if(visited[nr][nc]) continue;
			if(board[nr][nc]==1){
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
				break;
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<10;i++){
		memset(board,0,sizeof(board));
		vector <int> cols;
		minVal=INF;
		answer=-1;
		cin>>testcase;
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				cin>>board[r][c];
				if(r==0&&board[r][c]==1) cols.push_back(c);
			}
		}
		for(int j=0;j<cols.size();j++){
			memset(visited,0,sizeof(visited));
			GoDown(cols[j]);
		}
		cout<<"#"<<testcase<<" "<<answer<<endl;
	}
	return 0;
}
