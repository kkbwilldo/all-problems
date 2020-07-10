#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int numNodes,numOps;
int type,a,b;
vector <int> parents;

int GetParent(int node){
	if(parents[node]==node) return node;
	else return GetParent(parents[node]);
}

void Union(int nodeA,int nodeB){
	int parentA=GetParent(nodeA);
	int parentB=GetParent(nodeB);
	if(parentA<parentB) parents[parentB]=parentA;
	else parents[parentA]=parentB;
}

bool isSameParent(int nodeA,int nodeB){
	int parentA=GetParent(nodeA);
	int parentB=GetParent(nodeB);
	if(parentA==parentB) return true;
	else return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNodes>>numOps;
	for(int i=0;i<=numNodes;i++) parents.push_back(i);
	for(int i=0;i<numOps;i++){
		cin>>type>>a>>b;
		if(type==0) Union(a,b);
		else if(isSameParent(a,b)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
