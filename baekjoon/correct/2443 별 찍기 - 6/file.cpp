#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int n;
	cin>>n;
	
	for(int i=n;i>0;i--){
		for(int j=0;j<n-i;j++) cout<<" ";
		for(int j=0;j<2*i-1;j++) cout<<"*";
		cout<<endl;
	}
	return 0;
}
