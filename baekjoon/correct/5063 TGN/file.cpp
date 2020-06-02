#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int testcase,profitN,profitP,cost;
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		cin>>profitN>>profitP>>cost;
		if(profitN<profitP-cost) cout<<"advertise"<<endl;
		else if(profitN>profitP-cost) cout<<"do not advertise"<<endl;
		else cout<<"does not matter"<<endl;
	}
	return 0;
}
