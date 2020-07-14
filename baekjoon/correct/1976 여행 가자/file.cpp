#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=210;

int numCities,numCitiesPlan;
int parents[MAX];
int adjs[MAX][MAX];
vector <int> nodes;


int GetParent(int a){
	if(parents[a]==a) return a;
	return GetParent(parents[a]);
}
void Union(int a,int b){
	int parentA=GetParent(a);
	int parentB=GetParent(b);
	if(parentA<parentB) parents[parentB]=parentA;
	else parents[parentA]=parentB;
}

bool isConnected(int a,int b){
	int parentA=GetParent(a);
	int parentB=GetParent(b);
	if(parentA==parentB) return true;
	else return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<MAX;i++) parents[i]=i;
	
	cin>>numCities>>numCitiesPlan;
	for(int r=0;r<numCities;r++){
		for(int c=0;c<numCities;c++){
			cin>>adjs[r][c];
			if(adjs[r][c]==1) Union(r+1,c+1);
		}
	}
	for(int i=0;i<numCitiesPlan;i++){
		int node;
		cin>>node;
		nodes.push_back(node);
	}
	
	bool connected=true;
	for(int i=0;i<nodes.size()-1;i++){
		if(isConnected(nodes[i],nodes[i+1])==false){
			connected=false;
			break;
		}
	}
	if(connected) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
