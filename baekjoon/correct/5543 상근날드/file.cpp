#include <iostream>
#include <algorithm>
using namespace std;

const int INF=987987987;
int cost,burger,beverage;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	burger=beverage=INF;
	
	for(int i=0;i<5;i++){
		cin>>cost;
		if(i<3) burger=min(burger,cost);
		else beverage=min(beverage,cost);
	}
	cout<<burger+beverage-50<<endl;
	return 0;
}
