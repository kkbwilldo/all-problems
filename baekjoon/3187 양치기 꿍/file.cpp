#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

const int MAX = 260;

int row,col;
int numS,numW;
int sheep,wolves;
int map[MAX][MAX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool visited[MAX][MAX];

void find(int sr,int sc){
	numS=0;numW=0;
	if(map[sr][sc]=='v') numW++;
	else if(map[sr][sc]=='k') numS++;
	visited[sr][sc]=true;
	queue<pair<int,int> > q;
	q.push(make_pair(sr,sc));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			if(nr<0||nr>=row||nc<0||nc>=col) continue;
			if(!visited[nr][nc]&&map[nr][nc]!='#'){
				visited[nr][nc]=true;		
				if(map[nr][nc]=='v') numW++;
				else if(map[nr][nc]=='k') numS++;
				q.push(make_pair(nr,nc));			
			}
		}
	}
	if(numS>numW) sheep+=numS;
	else wolves+=numW;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>row>>col;
	for(int i=0;i<row;i++){
		string str;
		cin>>str;
		for(int j=0;j<col;j++){
			map[i][j]=str[j];
		}
	}
	
	memset(visited,0,sizeof(visited));
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(map[i][j]!='#'){
				find(i,j);
			}
		}
	}

	cout<<sheep<<" "<<wolves<<endl;
	return 0;
}







