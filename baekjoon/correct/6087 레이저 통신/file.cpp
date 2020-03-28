#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX=110;

char map[MAX][MAX];
int ROW,COL;
int StartR,StartC,EndR,EndC;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int mirrors[MAX][MAX];
bool visited[MAX][MAX];
string str;

vector <pair<int,int> > terminals;

void Print(int type){
	if(type==1){
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cout<<mirrors[r][c]<<" ";
			}cout<<endl;
		}cout<<endl;
	}
	else{
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cout<<map[r][c]<<" ";
			}cout<<endl;
		}cout<<endl;
	}
}

void PutMirrors(){
	StartR=terminals[0].first;
	StartC=terminals[0].second;
	visited[StartR][StartC]=true;
	mirrors[StartR][StartC]=0;
	queue <pair<pair<int,int>,int> > q;
	for(int i=0;i<4;i++){
		int nr=StartR;
		int nc=StartC;
		while(1){
			nr+=dr[i];
			nc+=dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) break;
			if(map[nr][nc]=='*') break;
			visited[nr][nc]=true;
			mirrors[nr][nc]=0;
			q.push(make_pair(make_pair(nr,nc),0));
		}
	}
	while(!q.empty()){
		int r=q.front().first.first;
		int c=q.front().first.second;
		int mirror=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r;
			int nc=c;
			while(1){
				nr+=dr[i];
				nc+=dc[i];
				if(nr<0||nr>=ROW||nc<0||nc>=COL) break;
				if(map[nr][nc]=='*') break;
				if(visited[nr][nc]) continue;
				visited[nr][nc]=true;
				mirrors[nr][nc]=mirror+1;
				q.push(make_pair(make_pair(nr,nc),mirror+1));
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>COL>>ROW;
	for(int r=0;r<ROW;r++){
		cin>>str;
		for(int c=0;c<COL;c++){
			map[r][c]=str[c];
			if(map[r][c]=='C') terminals.push_back(make_pair(r,c));
		}
	}
	
	memset(mirrors,-1,sizeof(mirrors));
	PutMirrors();
	EndR=terminals[1].first;
	EndC=terminals[1].second;
	
	cout<<mirrors[EndR][EndC]<<endl;
	return 0;
}

