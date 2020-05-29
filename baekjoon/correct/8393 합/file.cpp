#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int n,sum;
	cin>>n;
	sum=0;
	for(int i=1;i<=n;i++) sum+=i;
	cout<<sum<<endl;
	return 0;
}
