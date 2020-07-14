#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int num,idx;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num>>idx;
	
	queue <int> q,answer;
	for(int i=1;i<=num;i++) q.push(i);
	while(!q.empty()){
		for(int i=1;i<=idx-1;i++){
			q.push(q.front());
			q.pop();
		}
		answer.push(q.front());
		q.pop();
	}
	cout<<"<";
	while(!answer.empty()){
		cout<<answer.front();
		answer.pop();
		if(!answer.empty()) cout<<", ";
	}
	cout<<">"<<endl;
	return 0;
}
