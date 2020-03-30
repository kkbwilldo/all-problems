#include <iostream>
#define endl '\n'
#define ull unsigned long long
using namespace std;

ull testcase,depth,target;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(ull test=1;test<=testcase;test++){
		cin>>depth>>target;
		cout<<"#"<<test<<" ";
		if(depth*2-1==target) cout<<1<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}
