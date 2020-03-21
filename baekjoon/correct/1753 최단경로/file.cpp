#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX = 20010;
const int INF = 987987987;

int numVertice,numEdges;
int startNode;
int Start,End,cost;

vector <int> adj[MAX];
vector <int> costs[MAX];
vector <int> dist(MAX, INF);

void dijkstra(int src){
	dist[src]=0;
	priority_queue <pair<int,int> > pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()){
		int cost=-pq.top().first;
		int curNode=pq.top().second;
		pq.pop();
		if(dist[curNode]<cost) continue;
		for(int i=0;i<adj[curNode].size();i++){
			int nextNode=adj[curNode][i];
			int nextDist=cost+costs[curNode][i];
			if(dist[nextNode]>nextDist){
				dist[nextNode]=nextDist;
				pq.push(make_pair(-nextDist,nextNode));
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numVertice>>numEdges>>startNode;
	for(int i=0;i<numEdges;i++){
		cin>>Start>>End>>cost;
		adj[Start].push_back(End);
		costs[Start].push_back(cost);
	}
	
	dijkstra(startNode);
	
	for(int i=1;i<=numVertice;i++){
		if(i==startNode) cout<<0<<endl;
		else if(dist[i]==INF) cout<<"INF"<<endl;
		else cout<<dist[i]<<endl;
	}
	
	return 0;
}
