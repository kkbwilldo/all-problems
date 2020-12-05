#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX=100000;

int parents[MAX+10];
bool visited[MAX+10];
vector <int> adjs[MAX+10];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int numNodes;
	cin>>numNodes;
	
	int a,b;
	for(int i=0;i<numNodes;i++){
		cin>>a>>b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}
	
	int root=1;
	parents[root]=root;
	visited[root]=true;
	queue <int> q;
	q.push(root);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i=0;i<adjs[node].size();i++){
			int Next = adjs[node][i];
			if(visited[Next]) continue;
			visited[Next]=true;
			parents[Next]=node;
			q.push(Next);
		}
	}
	
	for(int i=2;i<=numNodes;i++) cout<<parents[i]<<endl;
	return 0;
}
