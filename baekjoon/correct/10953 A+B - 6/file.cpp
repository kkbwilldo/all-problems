#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int testcase,A,B;
	string str;
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>str;
		int pos=str.find(",");
		A=stoi(str.substr(0,pos));
		B=stod(str.substr(pos+1,str.size()));
		cout<<A+B<<endl;
	}
	return 0;
}
