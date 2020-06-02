#include <iostream>
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int n;
	cin>>n;
	if(n>=90) cout<<"A"<<endl;
	else if(n>=80) cout<<"B"<<endl;
	else if(n>=70) cout<<"C"<<endl;
	else if(n>=60) cout<<"D"<<endl;
	else cout<<"F"<<endl;
	return 0;
}
