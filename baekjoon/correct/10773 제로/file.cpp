#include <iostream>
#include <stack>
#define ll long long
#define endl '\n'
using namespace std;

ll numCmds,num,answer;
stack <ll> s;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCmds;
	for(ll i=0;i<numCmds;i++){
		cin>>num;
		if(num!=0) s.push(num);
		else s.pop();
	}
	while(!s.empty()){
		answer+=s.top();
		s.pop();
	}
	cout<<answer<<endl;
	return 0;
}
