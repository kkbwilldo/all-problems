#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;

const int MAX = 110;
const int INF = 987987987;

char map[MAX][MAX];
int ROW,COL,numThrows;
int height,minDist,dist;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int label[MAX][MAX];
bool visited[MAX][MAX];
string str;

vector <pair<int,int> > pos;
vector <pair<int,int> >::size_type type;

void Chang(int height){
	int r=ROW-height;
	for(int c=0;c<COL;c++){
		if(map[r][c]=='x'){
			map[r][c]='.';
			break;
		}
	}
}

void Sang(int height){
	int r=ROW-height;
	for(int c=COL-1;c>=0;c--){
		if(map[r][c]=='x'){
			map[r][c]='.';
			break;
		}
	}
}

void Base(int x,int y){
	visited[x][y]=true;
	label[x][y]=1;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc]) continue;
			if(map[nr][nc]=='x'){
				label[nr][nc]=1;
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

void Floats(int x,int y){
	visited[x][y]=true;
	label[x][y]=2;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int r=q.front().first;
		int c=q.front().second;
		q.pop();
		pos.push_back(make_pair(r,c));
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc]) continue;
			if(map[nr][nc]=='x'){
				label[nr][nc]=2;
				visited[nr][nc]=true;
				q.push(make_pair(nr,nc));
			}
		}
	}
}

void CheckFloats(){
	memset(visited,0,sizeof(visited));
	memset(label,0,sizeof(label));
	pos.clear();
	for(int c=0;c<COL;c++){
		if(visited[ROW-1][c]) continue;
		if(map[ROW-1][c]=='x') Base(ROW-1,c);
	}
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(visited[r][c]) continue;
			if(map[r][c]=='x') Floats(r,c);
		}
	}
}

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.first>b.first) return true;
	return false;
}

void PullDown(){
	minDist=INF;
	sort(pos.begin(),pos.end(),cmp);
	for(type=0;type<pos.size();type++){
		int r=pos[type].first;
		int c=pos[type].second;
		int temp=r;
		dist=0;
		while(temp<ROW-1){
			if(label[temp+1][c]==2) temp++;
			else if(label[temp+1][c]==0){
				temp++;
				dist++;
			}
			else break;
		}
		minDist=min(minDist,dist);
	}
	for(type=0;type<pos.size();type++){
		int r=pos[type].first;
		int c=pos[type].second;
		map[r+minDist][c]='x';
		map[r][c]='.';
	}
}

void Print(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<map[r][c];
		}cout<<endl;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		cin>>str;
		for(int c=0;c<COL;c++) map[r][c]=str[c];
	}
	cin>>numThrows;

	for(int i=0;i<numThrows;i++){
		cin>>height;
		if(i%2==0) Chang(height);
		else Sang(height);
		CheckFloats();
		if(pos.size()>0) PullDown();
	}
	Print();
	return 0;
}

