#include <iostream>
#define endl '\n'
using namespace std;

void Rest(int cnt){
	if(cnt<=0) return;
	cout<<" *";
	Rest(cnt-1);
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-i;j++) cout<<" ";
		cout<<"*";
		Rest(i-1);
		cout<<endl;
	}
	return 0;
}
