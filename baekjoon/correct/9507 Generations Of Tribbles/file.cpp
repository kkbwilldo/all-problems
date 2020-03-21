#include <iostream>
using namespace std;

const int MAX = 70;

long long testcase,num;
long long DP[MAX];

long long koong(long long num){
	if(num<4) return DP[num];
	else{
		if(DP[num]==0){
			DP[num]=koong(num-4)+koong(num-3)+koong(num-2)+koong(num-1);
		}
		return DP[num];
	}
}

int main ()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	DP[0]=DP[1]=1;
	DP[2]=2;
	DP[3]=4;
	for(int test=1;test<=testcase;test++){
		cin>>num;
		cout<<koong(num)<<endl;
	}
	return 0;
}
