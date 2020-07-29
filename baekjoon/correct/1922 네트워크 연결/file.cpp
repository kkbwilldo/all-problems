#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=1010;

int numComs,numLines,answer;
int a,b,cost;
int parents[MAX];
vector <tuple<int,int,int> > info;

int GetParent(int node){
	if(parents[node]==node) return node;
	return parents[node]=GetParent(parents[node]);
}

void Union(int a,int b){
	int parentA=GetParent(a);
	int parentB=GetParent(b);
	if(parentA<parentB) parents[parentB]=parentA;
	else parents[parentA]=parentB;
}

bool isSameParent(int a,int b){
	int parentA=GetParent(a);
	int parentB=GetParent(b);
	if(parentA==parentB) return true;
	else return false;
}

bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
	return get<2>(a)<get<2>(b);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<MAX;i++) parents[i]=i;
	
	cin>>numComs>>numLines;
	for(int i=0;i<numLines;i++){
		cin>>a>>b>>cost;
		info.push_back(make_tuple(a,b,cost));
	}
	
	sort(info.begin(),info.end(),cmp);
	
	for(int i=0;i<numLines;i++){
		tie(a,b,cost)=info[i];
		if(isSameParent(a,b)==false){
			Union(a,b);
			answer+=cost;
		}
	}
	
	cout<<answer<<endl;
	return 0;
}
