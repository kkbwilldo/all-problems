#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
#define endl '\n'
using namespace std;

const int MAX=10000;

int numNodes,idx,maxLevel;
int levels[MAX+10];
int orders[MAX+10];
int mins[MAX+10];
int maxs[MAX+10];
int parents[MAX+10];
unordered_map <int,pair<int,int> > nodes;

void Inorder(int root,int level){
	if(root==-1){
		return;
	}
	Inorder(nodes[root].first,level+1);
	
	orders[root]=idx;
	levels[root]=level;
	if(maxLevel<level){
		maxLevel=level;
	}
	if(mins[level]>orders[root]){
		mins[level]=orders[root];
	}
	if(maxs[level]<orders[root]){
		maxs[level]=orders[root];
	}
	idx++;
	
	Inorder(nodes[root].second,level+1);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<MAX;i++){
		mins[i]=987987978;
	}
	
	cin>>numNodes;
	for(int i=1;i<=numNodes;i++) parents[i]=i;
	for(int i=0;i<numNodes;i++){
		int node,Left,Right;
		cin>>node>>Left>>Right;
		parents[Left]=parents[Right]=node;
		nodes[node]=make_pair(Left,Right);
	}
	
	int root=-1;
	for(int i=1;i<=numNodes;i++){
		if(i==parents[i]) {
		root=i;
		break;
		}
	}
	idx=1;
	Inorder(root,1);
	int answerIdx=-1,maxLen=0;
	for(int i=1;i<=maxLevel;i++){
		int len=maxs[i]-mins[i]+1;
		if(maxLen<len){
			answerIdx=i;
			maxLen=len;
		}
	}
	
	cout<<answerIdx<<" "<<maxLen<<endl;
	return 0;
}
