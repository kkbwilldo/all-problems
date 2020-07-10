#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
const int MAX=10010;

bool constructors[MAX];

void SetConstructors(string num){
	int val=stoi(num);
	for(int i=0;i<num.size();i++){
		val+=num[i]-'0';
	}
	constructors[val]=true;
}

int main ()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	for(int i=1;i<=10000;i++) SetConstructors(to_string(i));
	for(int i=1;i<=10000;i++){
		if(constructors[i]==false) cout<<i<<endl;
	}
	
	return 0;
}
