#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=10010;

int testcase;
int num,cnt;
int numbers[MAX];

void Division(int depth,int sum,int prev){
	if(sum>num) return;
	if(sum==num){
		cnt++;
		for(int i=0;i<depth-1;i++) cout<<numbers[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=3;i>0;i--){
		if(prev<i) continue;
		numbers[depth]=i;
		Division(depth+1,sum+i,i);
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num;
		cnt=0;
		Division(0,0,num);
		cout<<cnt<<endl;
	}
	
	return 0;
}
