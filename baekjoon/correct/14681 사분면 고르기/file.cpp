#include <iostream>
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int A,B;
	cin>>A>>B;
	if(A>0&&B>0) cout<<1<<endl;
	else if(A<0&&B>0) cout<<2<<endl;
	else if(A<0&&B<0) cout<<3<<endl;
	else cout<<4<<endl;
	return 0;
}
