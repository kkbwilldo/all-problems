#include <iostream>
#include <string>
#include <stack>
#define endl '\n'
using namespace std;

int numCmds,num;
string cmd;
stack <int> s;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCmds;
	for(int i=0;i<numCmds;i++){
		cin>>cmd;
		if(cmd=="push"){
			cin>>num;
			s.push(num);
		}
		else if(cmd=="pop"){
			if(s.empty()) cout<<-1<<endl;
			else{
				cout<<s.top()<<endl;
				s.pop();
			}
		}
		else if(cmd=="size"){
			cout<<s.size()<<endl;
		}
		else if(cmd=="empty"){
			if(s.empty()) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else if(cmd=="top"){
			if(s.empty()) cout<<-1<<endl;
			else cout<<s.top()<<endl;
		}
	}
	return 0;
}
