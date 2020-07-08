#include <iostream>
#include <algorithm>
#include <vector>
#define ull unsigned long long
#define endl '\n'
using namespace std;

int testcase,size;
ull num,answer;
vector <ull> nums;

ull GCD(ull a,ull b){
	while(b!=0){
		ull r = a%b;
		a=b;
		b=r;
	}
	return a;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		nums.clear();
		answer=0;
		cin>>size;
		for(int i=0;i<size;i++){
			cin>>num;
			nums.push_back(num);
		}
		
	}
	return 0;
}
