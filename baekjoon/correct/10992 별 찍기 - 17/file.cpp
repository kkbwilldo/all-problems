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
		if(n>1&&2<=i&&i<n){
			for(int j=0;j<2*(i-1)-1;j++) cout<<" ";
			cout<<"*";
		}
		else if(n>1&&i==n){
			for(int j=0;j<2*(i-1);j++) cout<<"*";
		}
		cout<<endl;
	}
	
	return 0;
}
