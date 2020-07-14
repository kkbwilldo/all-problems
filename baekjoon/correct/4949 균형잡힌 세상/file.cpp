#include <iostream>
#include <string>
#include <stack>
#define endl '\n'
using namespace std;

char letter;
bool VPS;
string str;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	while(1){
		getline(cin,str);
		if(str==".") break;
		VPS=true;
		stack <char> s;
		for(int i=0;i<str.size();i++){
			letter=str[i];
			if(letter=='('){
				s.push(letter);
			}
			else if(letter==')'){
				if(s.empty()||s.top()!='('){
					VPS=false;
					break;
				}
				else s.pop();
			}
			else if(letter=='['){
				s.push(letter);
			}
			else if(letter==']'){
				if(s.empty()||s.top()!='['){
					VPS=false;
					break;
				}
				else s.pop();
			}
		}
		if(!s.empty()) VPS=false;
		if(VPS) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
