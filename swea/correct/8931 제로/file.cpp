#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100010;

int testcase,trial,won,sum;

struct Stack{
	int money[MAX];
	int idx;
	
	void init() {memset(money,0,sizeof(money));idx=0;}
	void push(int won) {money[idx++]=won;}
	void pop() {idx--;}
	int top() {
		if(idx<=0) return -1;
		else return money[idx-1];
	}
};


int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		Stack s;
		s.init();
		cin>>trial;
		
		for(int i=0;i<trial;i++){
			cin>>won;
			if(won!=0) s.push(won);
			else s.pop();
		}
		
		sum=0;
		while(s.top()!=-1){
			sum+=s.top();
			s.pop();
		}
		cout<<"#"<<test<<" "<<sum<<endl;
	}
	return 0;
}
