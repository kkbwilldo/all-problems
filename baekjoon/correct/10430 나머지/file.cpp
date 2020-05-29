#include <iostream>
#define endl '\n'
using namespace std;

int A,B,C;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>A>>B>>C;
	
	cout<<(A+B)%C<<endl;
	cout<<((A%C)+(B%C))%C<<endl;
	cout<<(A*B)%C<<endl;
	cout<<((A%C)*(B%C))%C<<endl;
	return 0;
}
