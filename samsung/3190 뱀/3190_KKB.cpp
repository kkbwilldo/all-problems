#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

const int MAX = 110;

int size;
int numApples,numCmds;
int r,c,nr,nc;
int curTime,curDir;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int Map[MAX][MAX];
bool visited[MAX][MAX];

vector <tuple<int,int> > pos;
map<int,char> timeTable;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>numApples;
	for(int i=0;i<numApples;i++){
		int x,y;
		cin>>x>>y;
		Map[x][y]=1;
	}
	cin>>numCmds;
	for(int i=0;i<numCmds;i++){
		int clk;
		char dir;
		cin>>clk>>dir;
		timeTable[clk]=dir;
	}
	curTime=0;curDir=1;
	r=c=1;
	visited[r][c]=true;
	pos.insert(pos.begin(),make_tuple(r,c));
	while(1){
		curTime++;
		nr=r+dr[curDir];
		nc=c+dc[curDir];
		if(nr<1||nr>=size+1||nc<1||nc>=size+1) break;
		if(visited[nr][nc]) break;
		visited[nr][nc]=true;
		r=nr;
		c=nc;
		pos.insert(pos.begin(),make_tuple(nr,nc));
		if(Map[nr][nc]!=1){
			int x=get<0>(pos.back());
			int y=get<1>(pos.back());
			visited[x][y]=false;
			pos.pop_back();
		}
		else{
			Map[nr][nc]=0;
		}
		if(timeTable.find(curTime)!=timeTable.end()){
			if(timeTable[curTime]=='L') curDir=(curDir+4-1)%4; // 여기서 (curDir-1)%4 해서 틀림
			else curDir=(curDir+1)%4;
		}
	}
	cout<<curTime<<endl;
	return 0;
}
