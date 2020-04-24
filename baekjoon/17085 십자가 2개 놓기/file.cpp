#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

const int MAX = 18;
const int INF = 987987987;

char board[MAX][MAX];
int ROW,COL;
int maxVal,minVal;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int sizeMap[MAX][MAX];
bool visited[MAX][MAX];
string str;

vector <tuple<int,int> > pos;

void GetPos(){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(sizeMap[r][c]!=-1) pos.push_back(make_tuple(r,c));
		}
	}
}

bool NoContact(int ar,int ac,int asize,int br,int bc,int bsize){
	memset(visited,0,sizeof(visited));
	visited[ar][ac]=visited[br][bc]=true;
	for(int i=0;i<4;i++){
		int nr=ar,nc=ac;
		for(int j=0;j<asize;j++){
			nr+=dr[i];
			nc+=dc[i];
			visited[nr][nc]=true;
		}
	}
	for(int i=0;i<4;i++){
		int nr=br,nc=bc;
		for(int j=0;j<bsize;j++){
			nr+=dr[i];
			nc+=dc[i];
			if(visited[nr][nc]) return false;
			visited[nr][nc]=true;
		}
	}
	return true;
}

void MarkSize(){
	memset(sizeMap,-1,sizeof(sizeMap));
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			if(board[r][c]!='#') continue;
			minVal=INF;
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				int cnt=0;
				while(1){
					if(nr<0||nr>=ROW||nc<0||nc>=COL) break;
					if(board[nr][nc]=='.') break;
					nr+=dr[i];
					nc+=dc[i];
					cnt++;
				}
				minVal=min(minVal,cnt);
			}
			sizeMap[r][c]=minVal;
		}
	}
}

void AllCases(){
	for(int i=0;i<pos.size()-1;i++){
		for(int j=i+1;j<pos.size();j++){
			int ar,ac,br,bc;
			tie(ar,ac)=pos[i];
			tie(br,bc)=pos[j];
			int asize=sizeMap[ar][ac];
			int bsize=sizeMap[br][bc];
			for(int sizeA=asize;sizeA>0;sizeA--){
				if(NoContact(ar,ac,sizeA,br,bc,bsize)){
					int area=(sizeA*4+1)*(bsize*4+1);
					if(area<maxVal) break;
					maxVal=area;
					break;
				}
			}
			for(int sizeB=bsize;sizeB>0;sizeB--){
				if(NoContact(br,bc,sizeB,ar,ac,asize)){
					int area=(asize*4+1)*(sizeB*4+1);
					if(area<maxVal) break;
					maxVal=area;
					break;
				}
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		cin>>str;
		for(int c=0;c<COL;c++){
			board[r][c]=str[c];
		}
	}
	MarkSize();
	GetPos();
	AllCases();
	cout<<maxVal<<endl;
	return 0;
}
