#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=10000;
const int INF=987987987;

int numNodes;
int parent,child,dist;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNodes;

	int parents[numNodes+1]={0,};
	int dists[numNodes+1][numNodes+1];

	for(int i=1;i<=numNodes;i++){
		for(int j=1;j<=numNodes;j++){
			dists[i][j]=INF;
		}
	}
	for(int i=0;i<numNodes;i++){
		parents[i+1]=i+1;
		cin>>parent>>child>>dist;
		dists[parent][child]=dists[child][parent]=dist;
	}
	
	for(int Mid=1;Mid<=numNodes;Mid++){
		for(int Start=1;Start<=numNodes;Start++){
			for(int End=1;End<=numNodes;End++){
				if(dists[Start][Mid]!=INF&&dists[Mid][End]!=INF){
					dists[Start][End]=min(dists[Start][End],dists[Start][Mid]+dists[Mid][End]);
				}
			}
		}
	}
	
	int answer=0;
	for(int i=1;i<=numNodes;i++){
		for(int j=1;j<=numNodes;j++){
			answer=max(answer,dists[i][j]);
		}
	}
	cout<<answer<<endl;
	return 0;
}
