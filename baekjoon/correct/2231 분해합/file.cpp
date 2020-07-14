#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int num,answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	
	for(int i=1;i<=1000000;i++){
		string str=to_string(i);
		int sum=i;
		for(int j=0;j<str.size();j++) sum+=str[j]-'0';
		if(sum==num){
			answer=i;
			break;
		}
	}
	cout<<answer<<endl;
	return 0;
}
