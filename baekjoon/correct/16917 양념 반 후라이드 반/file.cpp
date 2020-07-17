#include <iostream>
#include <algorithm>
#define ll long long
#define endl '\n'
using namespace std;

ll Yangnyum,Fried,Banban;
ll leastY,leastF;
ll answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>Yangnyum>>Fried>>Banban>>leastY>>leastF;
	
	answer=min(leastF,leastY)*min(Fried+Yangnyum,2*Banban);
	
	if(leastF>leastY){
		ll least=leastF-leastY;
		answer+=min(least*Fried,2*least*Banban);
	}
	else if(leastF<leastY){
		ll least=leastY-leastF;
		answer+=min(least*Yangnyum,2*least*Banban);
	}
	cout<<answer<<endl;
	return 0;
}
