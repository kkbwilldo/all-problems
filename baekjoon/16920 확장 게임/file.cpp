#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

const int MAX=1010;

char board[MAX][MAX];
int ROW,COL,numPlayers;
int info[15];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

vector <pair<int,int> > pos[15];
unordered_map <char,int> counts;

void bfs(int StartR,int StartC,int StartDist){
	queue <tuple<int,int,int> > q;
	q.push(make_tuple(StartR,StartC,StartDist));
	char reference=board[StartR][StartC];
	while(!q.empty()){
		int r,c,dist;
		tie(r,c,dist)=q.front();
		q.pop();
		if(dist<=0) continue;
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int ndist=dist-1;
			if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
			if(board[nr][nc]!='.') continue;
			board[nr][nc]=reference;
			if(ndist<=0) pos[reference-'0'].push_back(make_pair(nr,nc));
			q.push(make_tuple(nr,nc,ndist));
		}
	}
}

void Play(){
	int cnt=0;
	while(cnt<9){
		cnt=0;
		for(int i=1;i<=9;i++){
			unsigned size=pos[i].size();
			for(int j=0;j<size;j++){
				int r=pos[i][j].first;
				int c=pos[i][j].second;
				int dist=info[i];
				bfs(r,c,dist);
			}
			pos[i].erase(pos[i].begin(),pos[i].begin()+size);
		}
		for(int i=1;i<=9;i++){
			if(pos[i].size()==0) cnt++;
		}
	}
}

void Check(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(counts.find(board[r][c])==counts.end()) counts[board[r][c]]=1;
			else counts[board[r][c]]++;
		}
	}
}

void Print(){
	for(int i=1;i<=9;i++){
		if(counts.find(i+'0')!=counts.end()) cout<<counts[i+'0']<<" ";
	}cout<<endl;
}

void PrintTest(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<board[r][c]<<" ";
		}cout<<endl;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>numPlayers;
	for(int i=1;i<=numPlayers;i++) cin>>info[i];
	for(int r=0;r<ROW;r++){
		string str;
		cin>>str;
		for(int c=0;c<COL;c++){
			board[r][c]=str[c];
			if('1'<=board[r][c]&&board[r][c]<='9'){
				pos[board[r][c]-'0'].push_back(make_pair(r,c));
			}
		}
	}
	Play();
	Check();
	Print();
	//PrintTest();
	return 0;
}
