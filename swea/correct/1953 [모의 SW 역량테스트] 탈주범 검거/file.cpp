#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 50;

struct node{
	int x,y,clk;
	node(int inputX,int inputY,int inputClk){
		x = inputX;
		y = inputY;
		clk = inputClk;
	}
};

int testcase,row,col,due,cnt;
int startR,startC;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int map[MAX][MAX];
bool visited[MAX][MAX];
bool dir[4],nextDir[4];

void findDir(int x,int y,bool *dir){
	int type = map[x][y];
	if(!type) return;
	for(int i=0;i<4;i++) dir[i]=true;
	if(type == 2) dir[1]=dir[3]=false;
	else if(type == 3) dir[0]=dir[2]=false;
	else if(type == 4) dir[2]=dir[3]=false;
	else if(type == 5) dir[0]=dir[3]=false;
	else if(type == 6) dir[0]=dir[1]=false;
	else if(type == 7) dir[1]=dir[2]=false;
}

void bfs(int startX,int startY){
	cnt = 0;
	queue <node> q;
	visited[startX][startY] = true;
	q.push(node(startX,startY,1));
	while(!q.empty()){
		cnt++;
		int x = q.front().x;
		int y = q.front().y;
		int clk = q.front().clk;
		q.pop();
		findDir(x,y,dir);
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nextClk = clk + 1;
			if(nx<0||nx>=row||ny<0||ny>=col) continue;
			if(nextClk>due) continue;
			if(!map[nx][ny]) continue;
			if(!dir[i]) continue;
			findDir(nx,ny,nextDir);
			if(!visited[nx][ny]){
				if(nextDir[(i+2)%4]){ 				// 0 : (0+2)%4=2  2 : (2+2)%4=0 
					q.push(node(nx,ny,nextClk));// 1 : (1+2)%4=3  3 : (3+2)%4=1
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test = 1;test<=testcase;test++){
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		cin>>row>>col>>startR>>startC>>due;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>map[i][j];
			}
		}
		bfs(startR,startC);
		cout<<"#"<<test<<" "<<cnt<<endl;
	}
	return 0;
}
