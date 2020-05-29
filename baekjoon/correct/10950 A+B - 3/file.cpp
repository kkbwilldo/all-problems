#include <iostream>
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int testcase,A,B;
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>A>>B;
		cout<<A+B<<endl;
	}
	return 0;
}
