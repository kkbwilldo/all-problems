#include <iostream>
#define ll long long
using namespace std;

const ll MAX = 1000010;

ll numClasses,numGenerals,numVices;
ll cnt;
ll classes[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numClasses;
	for(int i=0;i<numClasses;i++) cin>>classes[i];
	cin>>numGenerals>>numVices;
	cnt=numClasses;
	for(int i=0;i<numClasses;i++){
		ll Rest=classes[i]-numGenerals>=0?classes[i]-numGenerals:0;
		cnt+=Rest/numVices;
		if(Rest%numVices) cnt+=1;
	}
	cout<<cnt<<endl;
	return 0;
}
