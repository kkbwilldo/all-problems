#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=310;

int ROW,COL;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool visited[MAX][MAX];
vector <tuple<int,int,int> > pos;

int CountAdjs(int StartR,int StartC){
	memset(visited,0,sizeof(visited));
	visited[StartR][StartC]=true;
	int cnt=1;
	queue <tuple<int,int> > q;
	q.push(make_tuple(StartR,StartC));
	while(!q.empty()){
		int r,c;
		tie(r,c)=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(visited[nr][nc]) continue;
			if(board[nr][nc]==0) continue;
			visited[nr][nc]=true;
			cnt++;
			q.push(make_tuple(nr,nc));
		}
	}
	return cnt;
}

void MeltDown(){
	vector <tuple<int,int> > Erased;
	for(auto iter=pos.begin();iter!=pos.end();){
		int size,r,c;
		tie(size,r,c)=*iter;
		int cnt=0;
		for(int j=0;j<4;j++){
			int nr=r+dr[j];
			int nc=c+dc[j];
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(board[nr][nc]) continue;
			cnt++;
		}
		size-=cnt;
		if(size<=0){
			Erased.push_back(make_tuple(r,c));
			iter=pos.erase(iter);
		}
		else{
			get<0>(*iter)=size;
			board[r][c]=size; // 이걸 안했다!!!!!
			iter++;
		}
	}
	for(int i=0;i<Erased.size();i++){ // 한번에 지워야 한다!!!!!!
		int r,c;
		tie(r,c)=Erased[i];
		board[r][c]=0;
	}
}

void Print(int Time){
	cout<<"Time: "<<Time<<endl;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<board[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
			if(board[r][c]) pos.push_back(make_tuple(board[r][c],r,c));
		}
	}
	int Time=0;
	bool separated=false;
	//Print(Time);
	while(1){
		if(pos.size()<=1) break;
		int StartR=get<1>(pos[0]);
		int StartC=get<2>(pos[0]);
		int cnt=CountAdjs(StartR,StartC);
		if(cnt!=pos.size()){
			separated=true;
			break;
		}
		Time++;
		MeltDown();
		//Print(Time);		
	}
	if(!separated) Time=0;
	cout<<Time<<endl;
	return 0;
}
