#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int MAX = 55;
const int INF = 987987987;

int ROW,COL,numRots;
int r,c,margin;
int answer,minVal;
int map[MAX][MAX];

vector <tuple<int,int,int> > info;

void Copy(int temp[][MAX],int map[][MAX]){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			temp[r][c]=map[r][c];
		}
	}
}

void Rotate(int r,int c,int margin){
	for(int m=1;m<=margin;m++){
		int temp=map[r+m][c-m];
		for(int j=-m+1;j<=m;j++) map[r+m][c+j-1]=map[r+m][c+j];
		for(int j=m-1;j>=-m;j--) map[r+j+1][c+m]=map[r+j][c+m];
		for(int j=m-1;j>=-m;j--) map[r-m][c+j+1]=map[r-m][c+j];
		for(int j=-m+1;j<=m-1;j++) map[r+j-1][c-m]=map[r+j][c-m];
		map[r+m-1][c-m]=temp;
	}
}

int GetMin(){
	int minVal=INF;
	for(int r=0;r<ROW;r++){
		int sum=0;
		for(int c=0;c<COL;c++) sum+=map[r][c];
		minVal=min(minVal,sum);
	}
	return minVal;
}

void Print(int a[][MAX]){
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cout<<a[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void AllCases(){
	vector <int> indice;
	for(int i=0;i<numRots;i++) indice.push_back(i);
	answer=INF;
	do{
		int temp[MAX][MAX];
		Copy(temp,map);
		for(int i=0;i<indice.size();i++){
			int idx=indice[i];
			int r,c,margin;
			tie(r,c,margin)=info[idx];
			Rotate(r,c,margin);
		}
		minVal=GetMin();
		answer=min(answer,minVal);
		Copy(map,temp);
	}while(next_permutation(indice.begin(),indice.end()));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL>>numRots;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>map[r][c];
		}
	}
	
	for(int i=0;i<numRots;i++){
		cin>>r>>c>>margin;
		info.push_back(make_tuple(r-1,c-1,margin));
	}
	AllCases();
	cout<<answer<<endl;

	return 0;
}
