#include <iostream>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num,answer=1;
	cin>>num;
	for(int i=1;i<=num;i++) answer*=i;
	cout<<answer<<endl;
	return 0;
}
