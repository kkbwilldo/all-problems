#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

int numCmds,num;
string str;
deque <int> q;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCmds;
	for(int i=0;i<numCmds;i++){
		cin>>str;
		if(str=="push"){
			cin>>num;
			q.push_back(num);
		}
		else if(str=="pop"){
			if(q.empty()) cout<<-1<<endl;
			else{
				cout<<q.front()<<endl;
				q.pop_front();
			}
		}
		else if(str=="size"){
			cout<<q.size()<<endl;
		}
		else if(str=="empty"){
			if(q.empty()) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else if(str=="front"){
			if(q.empty()) cout<<-1<<endl;
			else cout<<q.front()<<endl;
		}
		else if(str=="back"){
			if(q.empty()) cout<<-1<<endl;
			else cout<<q.back()<<endl;
		}
	}
	return 0;
}
