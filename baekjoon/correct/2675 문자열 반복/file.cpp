#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int testcase;
int numIters;
string str;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numIters>>str;
		for(int i=0;i<str.size();i++){
			for(int iter=0;iter<numIters;iter++){
				cout<<str[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
