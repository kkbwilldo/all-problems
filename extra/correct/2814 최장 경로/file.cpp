#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
using namespace std;

const int MAX=30;

int testcase,numNodes,numPaths,answer;
int A,B;
bool visited[MAX];

vector <int> adj[MAX];
map <int,int> nodes;
map <pair<int,int>,int> paths;

void dfs(int curNode,int dist){
	answer=max(answer,dist);
	visited[curNode]=true;
	for(int i=0;i<adj[curNode].size();i++){
		int nextNode=adj[curNode][i];
		if(visited[nextNode]) continue;
		dfs(nextNode,dist+1);
	}
	visited[curNode]=false;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		nodes.clear();
		paths.clear();
		for(int i=0;i<MAX;i++) adj[i].clear();
		answer=1;
		cin>>numNodes>>numPaths;
		for(int i=0;i<numPaths;i++){
			cin>>A>>B;
			if(paths.find(make_pair(A,B))!=paths.end()) continue;
			paths[make_pair(A,B)]=1;
			paths[make_pair(B,A)]=1;
			adj[A].push_back(B);
			adj[B].push_back(A);
			nodes[A]=1;
			nodes[B]=1;
		}
		for(auto iter=nodes.begin();iter!=nodes.end();iter++){
			dfs(iter->first,1);
		}
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
