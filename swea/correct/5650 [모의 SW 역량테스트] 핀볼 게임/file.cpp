#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <cstring>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=110;

int testcase,maxVal,result,size;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];

unordered_map <int,vector<pair<int,int> > > wormHoles;

int ChangeDir(int type,int dir){
	if(type>=5){
		if(dir%2==0) return dir+1;
		else return dir-1;
	}
	else if(type==1){
		if(dir==1||dir==2) return (dir+2)%4;
		else return ChangeDir(5,dir);
	}
	else if(type==2){
		if(dir==0||dir==2) return (dir+4-1)%4;
		else return ChangeDir(5,dir);
	}
	else if(type==3){
		if(dir==0||dir==3) return (dir+2)%4;
		else return ChangeDir(5,dir);
	}
	else if(type==4){
		if(dir==1||dir==3) return (dir+1)%4;
		else return ChangeDir(5,dir);
	}
	return -1;
}

int Move(int StartR,int StartC,int StartDir){
	int r=StartR;
	int c=StartC;
	int dir=StartDir;
	int cnt=0;
	while(1){
		r+=dr[dir];
		c+=dc[dir];
		if(r<0||r>=size||c<0||c>=size){
			dir=ChangeDir(6,dir);
			cnt++;
		}
		else{
			if(r==StartR&&c==StartC) break;
			else if(board[r][c]==-1) break;
			else if(board[r][c]==0) continue;
			else if(6<=board[r][c]&&board[r][c]<=10){
				int holeNum=board[r][c];
				for(int i=0;i<2;i++){
					int pairR=wormHoles[holeNum][i].first;
					int pairC=wormHoles[holeNum][i].second;
					// 여기 때문에 49개만 맞음 ㅠㅠ &&가 아닌 ||로 바꿔서 패스했다
					if(r!=pairR||c!=pairC){ 
						r=pairR;
						c=pairC;
						break;
					}
				}
			}
			else{
				int blockNum=board[r][c];
				dir=ChangeDir(blockNum,dir);
				cnt++;
			}
		}
	}
	return cnt;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(board,0,sizeof(board));
		maxVal=0;
		wormHoles.clear();
		cin>>size;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				cin>>board[r][c];
				if(6<=board[r][c]&&board[r][c]<=10)
					wormHoles[board[r][c]].push_back(make_pair(r,c));
			}
		}
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){
				if(board[r][c]!=0) continue;
				for(int i=0;i<4;i++){
					result=Move(r,c,i);
					maxVal=max(maxVal,result);
				}
			}
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
