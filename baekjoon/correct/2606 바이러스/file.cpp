#include <iostream>
#include <queue>
using namespace std;

const int MAX=110;

int numComputers,numConnects,answer;
int board[MAX][MAX];
bool visited[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numComputers>>numConnects;
	for(int i=0;i<numConnects;i++){
		int a,b;
		cin>>a>>b;
		board[a][b]=board[b][a]=1;
	}
	
	visited[1]=true;
	queue <int> q;
	q.push(1);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		answer++;
		for(int i=0;i<MAX;i++){
			if(board[node][i]==0) continue;
			if(visited[i]) continue;
			visited[i]=true;
			q.push(i);
		}
	}
	if(answer!=0) answer--;
	cout<<answer<<endl;
	return 0;
}
