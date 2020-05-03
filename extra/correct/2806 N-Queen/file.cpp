#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX = 30;

int testcase,answer,size;
bool cols[MAX],upperDiag[MAX],lowerDiag[MAX];

void PutQueens(int depth){
	if(depth==size){
		answer++;
		return;
	}
	for(int c=0;c<size;c++){
		if(cols[c]) continue;
		if(upperDiag[depth+c]) continue;
		int idx=depth-c;
		if(idx<0) idx=-idx+(size-1);
		if(lowerDiag[idx]) continue;
		cols[c]=upperDiag[depth+c]=lowerDiag[idx]=true;
		PutQueens(depth+1);
		cols[c]=upperDiag[depth+c]=lowerDiag[idx]=false;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(cols,0,sizeof(cols));
		memset(upperDiag,0,sizeof(upperDiag));
		memset(lowerDiag,0,sizeof(lowerDiag));
		answer=0;
		cin>>size;
		PutQueens(0);
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
