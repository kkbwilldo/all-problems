#include <iostream>
#include <queue>
#define ull unsigned long long
#define endl '\n'
using namespace std;

ull num,card,sum,total,first,second;
priority_queue <ull> q;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(ull i=0;i<num;i++){
		cin>>card;
		q.push(-1*card);
	}
	for(ull i=1;i<num;i++){
		first=-q.top();
		q.pop();
		second=-q.top();
		q.pop();
		sum=first+second;
		q.push(-1*sum);
		total+=sum;
	}
	cout<<total<<endl;
	return 0;
}
