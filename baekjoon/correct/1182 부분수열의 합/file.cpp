#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll numNums,total,number,answer;
vector <ll> numbers;

void dfs(ll depth,ll sum){
	if(depth==numNums){
		if(sum==total) answer++;
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
	
	cin>>numNums>>total;
	for(int i=0;i<numNums;i++){
		cin>>number;
		numbers.push_back(number);
	}
	dfs(0,0);
	if(total==0) answer--; // 아무것도 더하지 않은 경우는 카운트 하지 않음 
	cout<<answer<<endl;
	return 0;
}
