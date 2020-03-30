#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10010;

int testcase;
int numComs,numWays,Start;
int dep,indep,took;
int numHacked,answer;
int cost[MAX];
bool check[MAX];

void BFS(vector <int> networks[MAX],vector <int> times[MAX],int s){
	for(int i=0;i<MAX;i++) cost[i]=987987987;
	cost[s]=0;
	numHacked=1;
	queue <int> q;
	q.push(s);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(unsigned int i=0;i!=networks[current].size();i++){
			int next = networks[current][i];
			if(cost[next]>cost[current]+times[current][i]){
				cost[next]=cost[current]+times[current][i];
				numHacked++;
				check[next]=true;
				q.push(next);
			}
		}
	}
	answer=0;
	for(int i=0;i<MAX;i++){
		if(cost[i]!=987987987) answer+=cost[i];
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=0;test<testcase;test++){
		vector <int> networks[MAX];
		vector <int> times[MAX];
		cin>>numComs>>numWays>>Start;
		for(int i=0;i<numWays;i++){
			cin>>dep>>indep>>took;
			networks[indep].push_back(dep);
			times[indep].push_back(took);
		}
		BFS(networks,times,Start);
		cout<<numHacked<<" "<<answer<<endl;
	}
	
	return 0;
}







