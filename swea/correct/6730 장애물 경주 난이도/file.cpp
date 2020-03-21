#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int testcase,num;
int Up,Down;
int cur,Next;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num>>cur;
		Up=Down=0;
		for(int i=0;i<num-1;i++){
			cin>>Next;
			if(cur>Next) Down=max(Down,cur-Next);
			else if(cur<Next) Up=max(Up,Next-cur);
			else{;}
			cur=Next;
		}
		cout<<"#"<<test<<" "<<Up<<" "<<Down<<endl;
	}
	return 0;
}
