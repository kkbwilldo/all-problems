#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=100005;

int numGates,numPlanes,gate,parent,answer;
int parents[MAX];

int GetParent(int a){
	if(parents[a]==a) return a;
	return parents[a]=GetParent(parents[a]);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numGates>>numPlanes;
	for(int i=0;i<=numGates;i++) parents[i]=i;
	for(int i=0;i<numPlanes;i++){
		cin>>gate;
		parent=GetParent(gate);
		if(parent==0) break;
		parents[parent]=parent-1;
		answer++;
	}
	cout<<answer<<endl;
	return 0;
}
