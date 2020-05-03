#include <iostream>
#include <unordered_map>
#include <string>
#define endl '\n'
using namespace std;

const int MAX=4;

int testcase;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];

unordered_map <string,int> numbers;

void dfs(int depth,int r,int c,string str){
	if(depth==7){
		if(numbers.find(str)==numbers.end()) numbers[str]=1;
		return;
	}
	for(int i=0;i<4;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(nr<0||nr>=MAX||nc<0||nc>=MAX) continue;
		dfs(depth+1,nr,nc,str+to_string(board[nr][nc]));
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	
	for(int test=1;test<=testcase;test++){
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				cin>>board[r][c];
			}
		}
		numbers.clear();
		for(int r=0;r<MAX;r++){
			for(int c=0;c<MAX;c++){
				dfs(0,r,c,"");
			}
		}
		cout<<"#"<<test<<" "<<numbers.size()<<endl;
	}
	return 0;
}
