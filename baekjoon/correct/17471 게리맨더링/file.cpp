#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX=13;
const int INF=987987987;


int numAreas,minVal;
int populations[MAX];
bool visited[MAX];
vector <int> adj[MAX];

void Search(vector <int> areaList,int rep){
	visited[rep]=true;
	for(int i=0;i<adj[rep].size();i++){
		int Next=adj[rep][i];
		if(visited[Next]) continue;
		for(int j=0;j<areaList.size();j++){
			if(Next==areaList[j]){
				Search(areaList,Next);
				break;
			}
		}
	}
}

void AllCases(){
	for(int numArea1=1;numArea1<=numAreas/2;numArea1++){
		vector <int> indice;
		for(int i=0;i<numArea1;i++) indice.push_back(1);
		for(int i=0;i<numAreas-numArea1;i++) indice.push_back(2);
		do{
			vector <int> area1,area2;
			for(int i=0;i<numAreas;i++){
				if(indice[i]==1) area1.push_back(i);
				else area2.push_back(i);
			}
			memset(visited,0,sizeof(visited));
			int rep1=area1[0];
			int rep2=area2[0];
			Search(area1,rep1);
			Search(area2,rep2);
			bool allSet=true;
			for(int i=0;i<numAreas;i++){
				if(visited[i]==false){
					allSet=false;
					break;
				}
			}
			if(allSet){
				int sum1=0,sum2=0;
				for(int i=0;i<numAreas;i++){
					if(indice[i]==1) sum1+=populations[i];
					else sum2+=populations[i];
				}
				minVal=min(minVal,abs(sum1-sum2));
			}
		}while(next_permutation(indice.begin(),indice.end()));
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numAreas;
	for(int i=0;i<numAreas;i++) cin>>populations[i];
	for(int i=0;i<numAreas;i++){
		int numAdjs;
		cin>>numAdjs;
		for(int j=0;j<numAdjs;j++){
			int node;
			cin>>node;
			adj[i].push_back(node-1);
		}
	}
	minVal=INF;
	AllCases();
	if(minVal==INF) minVal=-1;
	cout<<minVal<<endl;
	return 0;
}
