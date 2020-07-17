#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

const ll MAX=50;

ll num,answer;
ll DP[MAX];

ll Fibo(ll n){
	if(n<=1) return DP[n]=n;
	if(DP[n]!=0) return DP[n];
	DP[n]=Fibo(n-2)+Fibo(n-1);
	return DP[n];
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	answer=Fibo(num);
	cout<<answer<<endl;
	return 0;
}
