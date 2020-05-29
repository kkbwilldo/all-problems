#include <iostream>
#define endl '\n'
using namespace std;

int A;
string B;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>A>>B;
	for(int i=B.size()-1;i>=0;i--){
		int num=B[i]-'0';
		cout<<num*A<<endl;
	}
	cout<<stoi(B)*A<<endl;
	return 0;
}
