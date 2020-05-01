#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
using namespace std;

const int MAX=100;

int testcase,numPaths;
int Start,End;
bool visited[MAX];

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<10;i++){
		memset(visited,0,sizeof(visited));
		vector <int> adj[MAX];
		cin>>testcase>>numPaths;
		for(int j=0;j<numPaths;j++){
			cin>>Start>>End;
			adj[Start].push_back(End);
		}
		Start=0;End=99;
		visited[Start]=true;
		queue <int> q;
		q.push(Start);
		while(!q.empty()){
			int node=q.front();
			q.pop();
			for(int j=0;j<adj[node].size();j++){
				int nextNode=adj[node][j];
				if(visited[nextNode]) continue;
				visited[nextNode]=true;
				q.push(nextNode);
			}
		}
		cout<<"#"<<testcase<<" ";
		if(visited[End]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
