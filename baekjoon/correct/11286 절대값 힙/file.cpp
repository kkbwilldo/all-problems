#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int numCmds,num;
priority_queue <int,vector <int>, greater <int> > minHeap;
priority_queue <int> maxHeap;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCmds;
	for(int i=0;i<numCmds;i++){
		cin>>num;
		if(num<0) maxHeap.push(num);
		else if(num>0) minHeap.push(num);
		else{
			if(maxHeap.empty()&&minHeap.empty()) cout<<0<<endl;
			else if(!maxHeap.empty()&&!minHeap.empty()){
				int minus=maxHeap.top();
				int plus=minHeap.top();
				if(abs(minus)<=plus){
					cout<<minus<<endl;
					maxHeap.pop();
				}
				else{
					cout<<plus<<endl;
					minHeap.pop();
				}
			}
			else if(!maxHeap.empty()){
				int minus=maxHeap.top();
				cout<<minus<<endl;
				maxHeap.pop();
			}
			else if(!minHeap.empty()){
				int plus=minHeap.top();
				cout<<plus<<endl;
				minHeap.pop();
			}
		}
	}
	return 0;
}
