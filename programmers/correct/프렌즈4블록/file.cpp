#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#define endl '\n'

using namespace std;
const int MAX = 35;

char MainChar;
char map[MAX][MAX];
int ROW,COL,answer;
int dr[]={1,1,0};
int dc[]={0,1,1};
bool isPop;
bool visited[MAX][MAX];
vector <pair<int,int> > pos;

void CheckPop(){
	pos.clear();
	isPop=true;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			MainChar=map[r][c];
			if(MainChar=='X') continue;
			isPop=true;
			for(int i=0;i<3;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nr<0||nr>=ROW||nc<0||nc>=COL){
					isPop=false;
					break;
				}
				if(MainChar!=map[nr][nc]){
					isPop=false;
					break;
				}
			}
			if(isPop) pos.push_back(make_pair(r,c));
		}
	}
}

void Pop(){
	memset(visited,0,sizeof(visited));
	for(int i=0;i<pos.size();i++){
		int r=pos[i].first;
		int c=pos[i].second;
		if(!visited[r][c]){
			visited[r][c]=true;
			map[r][c]='X';
			answer++;
		}
		for(int j=0;j<3;j++){
			if(visited[r+dr[j]][c+dc[j]]) continue;
			visited[r+dr[j]][c+dc[j]]=true;
			map[r+dr[j]][c+dc[j]]='X';
			answer++;
		}
	}
}

void PullDown(){
	for(int r=ROW-2;r>=0;r--){
		for(int c=0;c<COL;c++){
			int temp=r;
			while(temp<ROW-1&&map[temp+1][c]=='X'){
				map[temp+1][c]=map[temp][c];
				map[temp][c]='X';
				temp++;
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	ROW=m;COL=n;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			map[i][j]=board[i][j];
		}
	}
	CheckPop();
	while(pos.size()>0){
		Pop();
		PullDown();
		CheckPop();
	}
	return answer;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<string> board;
	board.push_back("TTTANT");
	board.push_back("RRFACC");
	board.push_back("RRRFCC");
	board.push_back("TRRRAA");
	board.push_back("TTMMMF");
	board.push_back("TMMTTJ");
	int Output=solution(6,6,board);
	
	cout<<Output<<endl;
	
	return 0;
}


