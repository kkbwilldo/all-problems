/*
map 자료구조 이용
reverse_iterator 이용
*/
#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int numLogs;
string name,log;
map <string,int> logs;
map <string,int>::reverse_iterator iter;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numLogs;
	for(int i=0;i<numLogs;i++){
		cin>>name>>log;
		if(logs.find(name)==logs.end()) logs[name]=1;
		else logs.erase(name);
	}
	for(iter=logs.rbegin();iter!=logs.rend();iter++)
		cout<<iter->first<<endl;
	
	return 0;
}
