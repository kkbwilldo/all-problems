#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int MAX=10001;

int testcase,numNodes,a,b,answer;
vector <int> parents(MAX,-1);

void SetFamily(vector <int> &a,int node){
	a.push_back(node);
	int parent=parents[node];
	if(parent==-1) return;
	SetFamily(a,parent);
}

int GetParent(vector <int> &a,vector <int> &b){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j]) return a[i];
		}
	}
	return -1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numNodes;
		for(int i=0;i<MAX;i++) parents[i]=-1;
		for(int i=0;i<numNodes-1;i++){
			cin>>a>>b;
			parents[b]=a;
		}
		cin>>a>>b;
		vector <int> parentsA,parentsB;
		SetFamily(parentsA,a);
		SetFamily(parentsB,b);
		
		answer=GetParent(parentsA,parentsB);
		cout<<answer<<endl;
	}
	return 0;
}
