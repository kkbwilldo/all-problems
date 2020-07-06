#include <iostream>
#include <string>
#define endl '\n'
#define ull unsigned long long
using namespace std;

ull testcase,num,mod;
string answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num;
		while(num>10){
			num=(num/2)+1;
			num=(num/2)-1;
		}
		if(num==1||(6<=num&&num<=9)) answer="Bob";
		else answer="Alice";
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
