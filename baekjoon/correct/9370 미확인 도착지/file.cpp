#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int INF=987987987;

int testcase;
int numNodes,numRoads,numCandis;
int Start,nodeG,nodeH;
int a,b,cost;
int candidate;
int distsS[2001],distsG[2001],distsH[2001];

vector <int> candidates,answer;
vector <int> adjs[50001],costs[50001];

// 초기화
void Init(){
	answer.clear();
	candidates.clear();
	for(int i=0;i<50001;i++){
		adjs[i].clear();
		costs[i].clear();
	}
	for(int i=0;i<2001;i++){
		distsS[i]=INF;
		distsG[i]=INF;
		distsH[i]=INF;
	}
}

void Dijikstra(int Start, int (&dists)[2001]){
	// 다익스트라
	priority_queue <tuple<int,int> > q;
	dists[Start]=0;
	q.push(make_tuple(dists[Start],Start));
	while(!q.empty()){
		int dist,node;
		tie(dist,node)=q.top();
		dist*=-1;
		q.pop();
		if(dist>dists[node]) continue;
		for(int i=0;i<adjs[node].size();i++){
			int Next=adjs[node][i];
			int ncost=costs[node][i];
			if(dists[Next]>dist+ncost){
				dists[Next]=dist+ncost;
				q.push(make_tuple(-dists[Next],Next));
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		
		// 초기화 및 입력
		Init();
		cin>>numNodes>>numRoads>>numCandis;
		cin>>Start>>nodeG>>nodeH;
		
		// 다익스트라를 사용하기 위한 인접리스트 생성
		for(int i=0;i<numRoads;i++){
			cin>>a>>b>>cost;
			adjs[a].push_back(b);
			adjs[b].push_back(a);
			costs[a].push_back(cost);
			costs[b].push_back(cost);
		}
		
		for(int i=0;i<numCandis;i++){
			cin>>candidate;
			candidates.push_back(candidate);
		}
		
		sort(candidates.begin(),candidates.end());
		
		Dijikstra(Start,distsS);
		Dijikstra(nodeG,distsG);
		Dijikstra(nodeH,distsH);
		
		for(int i=0;i<numCandis;i++){
			int candidate=candidates[i];
			int S_C=distsS[candidate];
			int S_G_H_C=distsS[nodeG]+distsG[nodeH]+distsH[candidate];
			int S_H_G_C=distsS[nodeH]+distsH[nodeG]+distsG[candidate];
			if(S_C==S_G_H_C||S_C==S_H_G_C) answer.push_back(candidate);
		}

		for(int i=0;i<answer.size();i++){
			cout<<answer[i];
			if(i!=answer.size()-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
