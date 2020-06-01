#include <iostream>
#define endl '\n'
using namespace std;

int numNums,numPicks;
int numbers[10];

void AllCases(int depth){
	if(depth==numPicks){
		for(int i=0;i<numPicks;i++){
			cout<<numbers[i];
			if(i!=numPicks-1) cout<<" ";
		}cout<<endl;
		return;
	}
	for(int i=1;i<=numNums;i++){
		numbers[depth]=i;
		AllCases(depth+1);
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNums>>numPicks;
	AllCases(0);
	return 0;
}
