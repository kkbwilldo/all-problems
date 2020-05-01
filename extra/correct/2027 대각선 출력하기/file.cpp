#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i==j) cout<<"#";
			else cout<<"+";
		}cout<<endl;
	}
	return 0;
}
