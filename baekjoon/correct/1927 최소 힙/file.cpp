#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int numCmds,num;
priority_queue <int,vector <int>, greater <int> > q;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCmds;
	for(int i=0;i<numCmds;i++){
		cin>>num;
		if(num!=0) q.push(num);
		else if(!q.empty()){
			cout<<q.top()<<endl;
			q.pop();
		}
		else cout<<0<<endl;
	}
	return 0;
}
