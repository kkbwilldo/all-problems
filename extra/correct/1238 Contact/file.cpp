#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int MAX=110;

int testcase,numData,Start,From,To,answer;
int visited[MAX];

vector <int> adj[MAX];

void CallAcq(int Start){
	queue <pair<int,int> > q;
	visited[Start]=0;
	q.push(make_pair(Start,visited[Start]));
	while(!q.empty()){
		int node=q.front().first;
		int numCalls=q.front().second;
		q.pop();
		for(int i=0;i<adj[node].size();i++){
			int nextNode=adj[node][i];
			if(visited[nextNode]!=-1) continue;
			visited[nextNode]=numCalls+1;
			q.push(make_pair(nextNode,numCalls+1));
		}
	}
}

void FindLastAndBiggest(){
	vector <int> lasts;
	int maxVal=-1;
	for(int i=MAX-1;i>=1;i--){ // 거꾸로 진행 
		if(maxVal<visited[i]){
			maxVal=visited[i];
			lasts.clear();
			lasts.push_back(i);
		}
		else if(maxVal==visited[i]) lasts.push_back(i);
	}
	answer=lasts[0];
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int test=1;test<=10;test++){
		memset(visited,-1,sizeof(visited));
		for(int i=0;i<MAX;i++) adj[i].clear();
		cin>>numData>>Start;
		for(int i=0;i<numData/2;i++){
			cin>>From>>To;
			adj[From].push_back(To);
		}
		CallAcq(Start);
		FindLastAndBiggest();
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
} 
