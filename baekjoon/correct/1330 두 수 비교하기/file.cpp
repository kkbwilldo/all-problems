#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	ll A,B;
	
	cin>>A>>B;
	if(A>B) cout<<">"<<endl;
	else if(A<B) cout<<"<"<<endl;
	else cout<<"=="<<endl;
	return 0;
}
