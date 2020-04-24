#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

const int MAX = 12;

int testcase;
int size,numHoneys,maxHoneys;
int maxVal,first,second;
int honeys[MAX];
int map[MAX][MAX];

void comb(int r,int c,int depth,string type){
	if(depth==numHoneys){
		int sum=0,sqr=0;
		for(int i=0;i<numHoneys;i++){
			if(honeys[i]){
				sum+=map[r][c+i];
				sqr+=map[r][c+i]*map[r][c+i];
			}
		}
		if(sum>maxHoneys) return;
		if(type=="first") first = max(sqr,first);
		else second = max(sqr,second);
	}
	else{
		honeys[depth] = 0;
		comb(r,c,depth+1,type);
		honeys[depth] = 1;
		comb(r,c,depth+1,type);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>numHoneys>>maxHoneys;
		for(int r=0;r<size;r++){ // N^2
			for(int c=0;c<size;c++){
				cin>>map[r][c];
			}
		}
		maxVal = 0;
		for(int r=0;r<size;r++){
			for(int c=0;c<size;c++){ // N^2
				if(c+numHoneys-1>=size) break;
				first = second = 0;
				comb(r,c,0,"first"); // 2^N

				// 같은 행
				for(int j=c+numHoneys;j<size;j++){ // N*2^N
					if(j+numHoneys-1>=size) break;
					comb(r,j,0,"second"); 
				}
				// 밑 행
				for(int i=r+1;i<size;i++){ // N^2*2^N
					if(i>=size) break;
					for(int j=0;j<size;j++){
						if(j+numHoneys-1>=size) break;
						comb(i,j,0,"second");
					}
				}
				maxVal = max(maxVal,first+second);
			}
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
