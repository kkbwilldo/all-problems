#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20010;

vector <int> barns[MAX];

int numBarns,numWays;
int A,B;
int maxVal,idx,numIdx;
int dist[MAX];
bool check[MAX];

void BFS(){
	queue <int> q;
	check[1] = true;
	dist[1]=0;
	q.push(1);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(long unsigned int i=0;i<barns[current].size();i++){
			int next = barns[current][i];
			if(!check[next]){
				check[next]=true;
				q.push(next);
				dist[next]=dist[current]+1;
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt","r",stdin);
	cin>>numBarns>>numWays;
	for(int i=0;i<numWays;i++){
		cin>>A>>B;
		barns[A].push_back(B);
		barns[B].push_back(A);
	}
	BFS();

	maxVal=0;idx=-1;numIdx=0;
	for(int i=1;i<=numBarns;i++){
		if(dist[i]>maxVal){
			idx=i;
			maxVal=dist[i];
		}
	}
	for(int i=1;i<=numBarns;i++){
		if(dist[i]==maxVal) numIdx++;
	}
	
	cout<<idx<<" "<<maxVal<<" "<<numIdx<<endl;
	return 0;
}

