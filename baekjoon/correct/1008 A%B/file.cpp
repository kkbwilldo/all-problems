#include <iostream>
#define endl '\n'
using namespace std;

long double A,B;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>A>>B;
	cout<<fixed;
	cout.precision(20);
	cout<<A/B<<endl;
	return 0;
}
