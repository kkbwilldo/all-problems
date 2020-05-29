#include <iostream>
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int A,B;
	while(cin>>A){
		cin>>B;
		cout<<A+B<<endl;
	}
	return 0;
}
