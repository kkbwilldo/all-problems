#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-i;j++) cout<<" ";
		cout<<"*";
		for(int j=0;j<2*(i-1)-1;j++) cout<<" ";
		if(i!=1) cout<<"*";
		cout<<endl;
	}
	return 0;
}
