#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX=10000;
int numVertice,numEdges,Start;
bool visited[1010];

vector <int> adj[MAX+10];

void DFS(int node){
	visited[node]=true;
	cout<<node<<" ";
	for(int i=0;i<adj[node].size();i++){
		int Next=adj[node][i];
		if(visited[Next]) continue;
		DFS(Next);
	}
}

void BFS(int Start){
	memset(visited,0,sizeof(visited));
	visited[Start]=true;
	queue <int> q;
	q.push(Start);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=0;i<adj[node].size();i++){
			int Next=adj[node][i];
			if(visited[Next]) continue;
			visited[Next]=true;
			q.push(Next);
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numVertice>>numEdges>>Start;
	
	for(int i=0;i<numEdges;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	// 조건문이 맘에 안든다...i<MAX+10.....
	for(int i=0;i<MAX+10;i++){
		if(adj[i].size()>1) sort(adj[i].begin(),adj[i].end());
	}

	DFS(Start);
	cout<<endl;
	BFS(Start);
	cout<<endl;
	return 0;
}
