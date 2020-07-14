#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int num,divisor;
vector <int> divisors;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>divisor;
		divisors.push_back(divisor);
	}
	sort(divisors.begin(),divisors.end());
	cout<<divisors.front()*divisors.back()<<endl;
	return 0;
}
