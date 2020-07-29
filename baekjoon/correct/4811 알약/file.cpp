#include <iostream>
#include <algorithm>
#include <vector>
#define ull unsigned long long
#define endl '\n'
using namespace std;

const int MAX=35;
ull DP[MAX][MAX];

ull num,answer;

ull recur(ull whole,ull half){
	if(whole==0&&half==0){
		return 1;
	}
	if(DP[whole][half]!=0) return DP[whole][half];
	if(whole>0) DP[whole][half]+=recur(whole-1,half+1);
	if(half>0) DP[whole][half]+=recur(whole,half-1);
	return DP[whole][half];
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	while(1){
		cin>>num;
		if(num==0) break;
		answer=recur(num-1,1);
		cout<<answer<<endl;
	}
	return 0;
}
