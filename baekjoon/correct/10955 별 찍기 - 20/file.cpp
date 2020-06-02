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
		if(i%2!=0){
			for(int j=0;j<n;j++){
				cout<<"*";
				if(j!=n-1) cout<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<" ";
			for(int j=0;j<n;j++){
				cout<<"*";
				if(j!=n-1) cout<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}
