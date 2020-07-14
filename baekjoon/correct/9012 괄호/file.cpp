#include <iostream>
#include <string>
#include <stack>
#define endl '\n'
using namespace std;

int testcase;
bool VPS;
string str;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>str;
		stack <char> s;
		VPS=true;
		for(int i=0;i<str.size();i++){
			char letter=str[i];
			if(letter=='(') s.push(letter);
			else{
				if(!s.empty()) s.pop();
				else{
					VPS=false;
					break;
				}
			}
		}
		if(!s.empty()) VPS=false;
		if(VPS) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
