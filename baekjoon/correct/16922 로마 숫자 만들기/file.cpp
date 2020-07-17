#include <iostream>
#include <unordered_set>
#include <string>
#define endl '\n'
using namespace std;

int num;
int vals[4]={1,5,10,50};
unordered_set <int> answer;

void AllCases(int depth,int Cur,int sum){
	if(depth==num){
		answer.insert(sum);
		return;
	}
	for(int i=0;i<4;i++){
		char Next=i;
		if(Cur>Next) continue;
		AllCases(depth+1,Next,sum+vals[i]);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	
	AllCases(0,-1,0);
	
	cout<<answer.size()<<endl;
	
	return 0;
}
