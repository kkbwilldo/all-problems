#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
	int from,to,cost;
	bool operator < (const Edge &other) const{
		return cost<other.cost;
	}
};

const int MAX=10001;
int numVertice,numEdges;
int a,b,cost;
int answer;
int parents[MAX];

vector <Edge> edges;

int Find(int x){
	if(x==parents[x]) return x;
	else return parents[x]=Find(parents[x]);
}

void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	parents[x]=y;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numVertice>>numEdges;
	for(int i=1;i<=numVertice;i++) parents[i]=i;
	
	for(int i=0;i<numEdges;i++){
		cin>>a>>b>>cost;
		Edge edge;
		edge.from=a;
		edge.to=b;
		edge.cost=cost;
		edges.push_back(edge);
	}
	
	sort(edges.begin(),edges.end());
	
	for(int i=0;i<numEdges;i++){
		Edge e=edges[i];
		int x=Find(e.from);
		int y=Find(e.to);
		if(x!=y){
			Union(e.from,e.to);
			answer+=e.cost;
		}
	}
	cout<<answer<<endl;
	return 0;
}

