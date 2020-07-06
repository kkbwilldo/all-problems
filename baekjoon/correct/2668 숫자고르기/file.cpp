#include <iostream>
#include <cstring>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=110;
 
int numNums;
int adj[MAX],visited[MAX];
vector <int> answer;

void Search(int Start,int node){  
	if(visited[node]){
		if(node==Start) answer.push_back(Start);
	}
	else{
		visited[node]++;
		Search(Start,adj[node]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);

	cin>>numNums;

	for(int i=1;i<=numNums;i++) cin>>adj[i];
	for(int i=1;i<=numNums;i++){
		memset(visited,0,sizeof(visited));
		Search(i,i);
	}

	cout<<answer.size()<<endl;
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<endl;
	}

	return 0;
}
