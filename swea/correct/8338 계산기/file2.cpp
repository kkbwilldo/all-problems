#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 10;

int testcase,num,maxVal;
int numbers[MAX];

void calc(int depth,int sum){
	if(depth==num-1){
		maxVal=max(maxVal,sum);
		return;
	}
	if(numbers[depth+1]!=0&&sum!=0) calc(depth+1,sum*numbers[depth+1]);
	calc(depth+1,sum+numbers[depth+1]);
	
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		maxVal=0;
		cin>>num;
		for(int i=0;i<num;i++) cin>>numbers[i];
		calc(0,numbers[0]);
		cout<<"#"<<test<<" "<<maxVal<<'\n';
	}
	return 0;
}
