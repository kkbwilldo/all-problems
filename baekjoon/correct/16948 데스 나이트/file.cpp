#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX=210;

int size;
int StartR,StartC,EndR,EndC;
int minVal;
int dr[]={-2,-2,0,0,2,2};
int dc[]={-1,1,-2,2,-1,1};
bool visited[MAX][MAX];

void DeathKnight(){
	visited[StartR][StartC]=true;
	minVal=-1;
	int cnt=0;
	queue <pair<pair<int,int>,int > > q;
	q.push(make_pair(make_pair(StartR,StartC),cnt));
	while(!q.empty()){
		int r=q.front().first.first;
		int c=q.front().first.second;
		cnt=q.front().second;
		q.pop();
		if(r==EndR&&c==EndC){
			minVal=cnt;
			return;
		}
		for(int i=0;i<6;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(visited[nr][nc]) continue;
			visited[nr][nc]=true;
			q.push(make_pair(make_pair(nr,nc),cnt+1));
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	cin>>StartR>>StartC>>EndR>>EndC;
	DeathKnight();
	
	cout<<minVal<<endl;
	
	return 0;
}
