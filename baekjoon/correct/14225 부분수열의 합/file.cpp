#include <iostream>
#include <vector>
#define ull unsigned long long 
using namespace std;

const ull MAX=100001*20;

ull numNums,number;
bool check[MAX];
vector <ull> numbers;

void dfs(ull depth,ull sum){
	if(depth==numNums){
		check[sum]=true;
		return;
	}
	dfs(depth+1,sum+numbers[depth]);
	dfs(depth+1,sum);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNums;
	
	for(ull i=0;i<numNums;i++){
		cin>>number;
		numbers.push_back(number);
	}
	dfs(0,0);
	for(ull i=1;i<MAX;i++){
		if(check[i]==false){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
