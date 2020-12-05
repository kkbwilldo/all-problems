#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=10000;

int numNodes;
int node,child,dist;
int root,maxVal;
bool visited[MAX+10];
vector <int> adjs[MAX+10],dists[MAX+10];

void BFS(int rootNode){
	memset(visited,0,sizeof(visited));
	visited[rootNode]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(rootNode,0));
	while(!q.empty()){
		int cur=q.front().first;
		int total=q.front().second;
		if(total>maxVal){
			maxVal=total;
			root=cur;
		}
		q.pop();
		for(int i=0;i<adjs[cur].size();i++){
			int Next=adjs[cur][i];
			int ndist=dists[cur][i];
			if(visited[Next]) continue;
			visited[Next]=true;
			q.push(make_pair(Next,total+ndist));
		}
	}
}

/*
void DFS(int node,int total){
	if(maxVal<total){
		root=node;
		maxVal=total;
	}
	for(int i=0;i<adjs[node].size();i++){
		int Next=adjs[node][i];
		if(visited[Next]) continue;
		visited[Next]=true;
		DFS(Next,total+dists[node][i]);
		visited[Next]=false;
	}
}
*/

int main ()
{
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNodes;
	for(int i=0;i<numNodes-1;i++){
		cin>>node>>child>>dist;
		adjs[node].push_back(child);
		adjs[child].push_back(node);
		dists[node].push_back(dist);
		dists[child].push_back(dist);
	}
	
	BFS(1);
	int first=root;
	BFS(first);
	int second=root;
	
	//cout<<first<<" "<<second<<endl;
	cout<<maxVal<<endl;
	return 0;
}
