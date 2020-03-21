#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 100;
const int INF = 987987987;

int numVertice;
vector <int> adj[MAX];

vector <int> dijkstra(int src){
	vector <int> dist(numVertice,INF);
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
	return dist;
}
