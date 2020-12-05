#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N,num;
vector <int> V;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		if(V.empty() || V.back()<num) V.push_back(num);
		else{
			auto iter = lower_bound(V.begin(),V.end(),num);
			*iter=num;
		}
	}
	
	cout<<V.size()<<endl;
	return 0;
}
