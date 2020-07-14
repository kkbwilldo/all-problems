#include <iostream>
#define endl '\n'
using namespace std;

int a,b;

int GCD(int a,int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>a>>b;
	
	int gcd=GCD(a,b);
	int lcm=a*b/gcd;
	cout<<gcd<<endl<<lcm<<endl;
	
	return 0;
}
