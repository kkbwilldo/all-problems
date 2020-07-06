#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=1010;

int numNodes,numEdges;
int a,b,cost;
int parent[MAX];
vector <pair<int,int> > answer;
vector <tuple<int,int,int> > info;

bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
	return get<2>(a) < get<2>(b);
}

int GetParent(int node){
	if(parent[node]==node) return node;
	else return GetParent(parent[node]);
}

void Union(int nodeA,int nodeB){
	int parentA=GetParent(nodeA);
	int parentB=GetParent(nodeB);
	if(parentA<parentB) parent[parentB]=parentA;
	else parent[parentA]=parentB;
}

bool isCycle(int nodeA,int nodeB){
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
	
	cin>>numNodes>>numEdges;
	for(int i=0;i<numEdges;i++){
		cin>>a>>b>>cost;
		info.push_back(make_tuple(a,b,cost));
	}
	
	sort(info.begin(),info.end(),cmp);

	for(int i=1;i<=numNodes;i++) parent[i]=i;
	for(int i=0;i<info.size();i++){
		int nodeA,nodeB,cost;
		tie(nodeA,nodeB,cost)=info[i];
		if(isCycle(nodeA,nodeB)==false){
			answer.push_back(make_pair(nodeA,nodeB));
			Union(nodeA,nodeB);
		}
	}
	cout<<answer.size()<<endl;
	for(int i=0;i<answer.size();i++){
		cout<<answer[i].first<<" "<<answer[i].second<<endl;
	}
	return 0;
}

