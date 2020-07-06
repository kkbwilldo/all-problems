#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX=1010;
const int INF=987987987;

int numNodes,numEdges;
int a,b,cost;
int dists[MAX];
int parent[MAX];

vector <int> costs[MAX];
vector <int> adjs[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNodes>>numEdges;
	for(int i=0;i<numEdges;i++){
		cin>>a>>b>>cost;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
		costs[a].push_back(cost);
		costs[b].push_back(cost);
	}
	for(int i=1;i<=numNodes;i++) dists[i]=INF;
	
	dists[1]=0;
	priority_queue <pair<int,int> > q;
	q.push(make_pair(dists[1],1));
	while(!q.empty()){
		int dist=-q.top().first;
		int curNode=q.top().second;
		q.pop();
		if(dist>dists[curNode]) continue;
		for(int i=0;i<adjs[curNode].size();i++){
			int Next=adjs[curNode][i];
			int cost=costs[curNode][i];
			if(dists[Next]>dist+cost){
				dists[Next]=dist+cost;
				parent[Next]=curNode;
				q.push(make_pair(-dists[Next],Next));
			}
		}
	}
	cout<<numNodes-1<<endl;
	for(int i=2;i<=numNodes;i++){
		cout<<i<<" "<<parent[i]<<endl;
	}
	return 0;
}
