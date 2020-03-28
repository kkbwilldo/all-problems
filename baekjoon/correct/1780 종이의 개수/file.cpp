#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX = 3*3*3*3*3*3*3*3;

int Size;
int dr[]={0,0,0,1,1,1,2,2,2};
int dc[]={0,1,2,0,1,2,0,1,2};
int map[MAX][MAX];

unordered_map <string,int> papers;

bool isWholePaper(int x,int y,int size){
	int theNum=map[x][y];
	if(size==0) return false;
	if(size==1){
		if(theNum==-1) papers["-1"]++;
		if(theNum==0) papers["0"]++;
		if(theNum==1) papers["1"]++;
		return true;
	}
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			int R=x+r;
			int C=y+c;
			if(map[R][C]!=theNum) return false;
		}
	}
	if(theNum==-1) papers["-1"]++;
	if(theNum==0) papers["0"]++;
	if(theNum==1) papers["1"]++;
	return true;
}

void Divide(int x,int y,int size){
	if(isWholePaper(x,y,size)) return;
	for(int i=0;i<9;i++){
		int nx=x+dr[i]*size/3;
		int ny=y+dc[i]*size/3;
		Divide(nx,ny,size/3);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	papers["-1"]=0;papers["0"]=0;papers["1"]=0;
	cin>>Size;
	for(int r=0;r<Size;r++){
		for(int c=0;c<Size;c++){
			cin>>map[r][c];
		}
	}
	Divide(0,0,Size);
	cout<<papers["-1"]<<endl<<papers["0"]<<endl<<papers["1"]<<endl;
	return 0;
}
