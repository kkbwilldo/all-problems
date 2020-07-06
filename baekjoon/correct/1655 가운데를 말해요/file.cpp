#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int numNums,num;

priority_queue <int, vector<int>, less<int> > Lefts;
priority_queue <int, vector<int>, greater<int> > Rights;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNums;
	for(int i=0;i<numNums;i++){
		cin>>num;
		if(Lefts.size()==Rights.size()){
			if(Lefts.empty()){
				Lefts.push(num);
			}
			else{
				int Right=Rights.top();
				if(num>Right){
					Lefts.push(Right);
					Rights.pop();
					Rights.push(num);
				}
				else{
					Lefts.push(num);
				}
			}
		}
		else{
			int Left=Lefts.top();
			if(num<Left){
				Rights.push(Left);
				Lefts.pop();
				Lefts.push(num);
			}
			else{
				Rights.push(num);
			}
		}
		cout<<Lefts.top()<<endl;
	}
	return 0;
}
