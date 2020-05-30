#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=9;i++){
		cout<<n<<" * "<<i<<" = "<<n*i<<endl;
	}
	return 0;
}
