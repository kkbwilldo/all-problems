#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX = 50;

int numPicks;
int picks[MAX];
int indice[MAX];

void AllCases(int depth,int sum){
	if(depth==numPicks){
		if(sum==6){
			for(int i=0;i<numPicks;i++){
				if(indice[i])	 cout<<picks[i]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	indice[depth]=1;
	AllCases(depth+1,sum+1);	
	indice[depth]=0;
	AllCases(depth+1,sum);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPicks;
	while(1){
		if(numPicks==0) break;
		memset(picks,0,sizeof(picks));
		memset(indice,0,sizeof(indice));
		for(int i=0;i<numPicks;i++) cin>>picks[i];
		AllCases(0,0);
		cin>>numPicks;
		if(numPicks) cout<<endl;
	}
	
	return 0;
}

