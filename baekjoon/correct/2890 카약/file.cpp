#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=55;

int ROW,COL;
char board[MAX][MAX];

int ranks[15];
pair<int,int> pos[15];

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.second>b.second;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>board[r][c];
			int num=board[r][c]-'0';
			if(1<=num&&num<=9) pos[num]=make_pair(num,c);
		}
	}
	
	sort(pos+1,pos+10,cmp);
	
	int rank=1;
	int curRankPos=pos[1].second;
	for(int i=1;i<=9;i++){
		int num=pos[i].first;
		int curPos=pos[i].second;
		if(curRankPos==curPos) ranks[num]=rank;
		else{
			rank++;
			ranks[num]=rank;
			curRankPos=curPos;
		}
	}
	
	for(int i=1;i<=9;i++) cout<<ranks[i]<<endl;
	
	return 0;
}
