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
		for(int j=0;j<i;j++) cout<<"*";
		cout<<endl;
	}
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++) cout<<"*";
		cout<<endl;
	}
	return 0;
}
