#include <iostream>
#define endl '\n'
using namespace std;

int num;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	
	if(num==1){
		cout<<"*"<<endl;
		return 0;
	}
	for(int r=0;r<num;r++){
		for(int i=0;i<num;i++){
			if(i%2==0) cout<<"*";
			else cout<<" ";
		}
		cout<<endl;
		for(int i=0;i<num;i++){
			if(i%2==0) cout<<" ";
			else cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
