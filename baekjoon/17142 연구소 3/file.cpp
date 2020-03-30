#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

const int MAX = 55;
const int INF = 987987987;

int size,numSelects,minDist,maxDist;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
int dists[MAX][MAX];

vector <int> indice;
vector <pair<int,int> > Virus;

queue <pair<pair<int,int>,int> > VirusQ;

void Print(){
	cout<<"maxDist: "<<maxDist<<endl;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(dists[r][c]==INF) cout<<"X ";
			else cout<<dists[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void FindMaxDist(){
	maxDist=0;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(dists[r][c]==INF) continue;
			maxDist=max(maxDist,dists[r][c]);
		}
	}
}

void Spread(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			dists[r][c]=INF;
		}
	}
	while(!VirusQ.empty()){
		int r=VirusQ.front().first.first;
		int c=VirusQ.front().first.second;
		int dist=VirusQ.front().second;
		if(dists[r][c]>dist) dists[r][c]=dist;
		VirusQ.pop();
		for(int i=0;i<4;i++){
			int nr=r+dr[i];
			int nc=c+dc[i];
			int ndist=dist+1;
			if(nr<0||nr>=size||nc<0||nc>=size) continue;
			if(ndist>dists[nr][nc]) continue;
			if(map[nr][nc]==1) continue;
			if(map[nr][nc]==2) ndist--;
			VirusQ.push(make_pair(make_pair(nr,nc),ndist));
		}
	}
	FindMaxDist();
	if(minDist>maxDist) Print();
	minDist=min(minDist,maxDist);
}

void SelectAndSpread(){
	for(int i=0;i<Virus.size()-numSelects;i++) indice.push_back(0);
	for(int i=0;i<numSelects;i++) indice.push_back(1);
	do{
		while(!VirusQ.empty()) VirusQ.pop();
		for(int i=0;i<Virus.size();i++){
			int r=Virus[i].first;
			int c=Virus[i].second;
			if(indice[i]==1) VirusQ.push(make_pair(make_pair(r,c),0));
		}
		Spread();
	}while(next_permutation(indice.begin(),indice.end()));
}

void Init(){
	cin>>size>>numSelects;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>map[r][c];
			if(map[r][c]==2) Virus.push_back(make_pair(r,c));
		}
	}
	minDist=INF;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	Init();
	SelectAndSpread();
	cout<<minDist<<endl;
	
	return 0;
}









