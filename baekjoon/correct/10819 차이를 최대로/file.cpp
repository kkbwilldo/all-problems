#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll numNums,num,sum,maxVal;

vector <ll> numbers;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNums;
	for(int i=0;i<numNums;i++){
		cin>>num;
		numbers.push_back(num);
	}
	sort(numbers.begin(),numbers.end());
	
	do{
		sum=0;
		for(int i=0;i<numNums-1;i++) sum+=abs(numbers[i]-numbers[i+1]);
		maxVal=max(maxVal,sum);
	}while(next_permutation(numbers.begin(),numbers.end()));
	cout<<maxVal<<endl;
	return 0;
}
