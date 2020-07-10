#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int size,numPops,idx,answer;
deque <int> q;

void MoveLeft(){
	int idx=q.front();
	q.pop_front();
	q.push_back(idx);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>numPops;
	for(int i=1;i<=size;i++) q.push_back(i);
	for(int i=0;i<numPops;i++){
		cin>>idx;
		int cnt=0;
		while(1){
			MoveLeft();
			cnt++;
			if(q.front()==idx){
				int val=cnt<q.size()-cnt?cnt:q.size()-cnt;
				answer+=val;
				q.pop_front();
				break;
			}
		}
	}

	cout<<answer<<endl;
	return 0;
}
