#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAX = 55;
const int INF = 987987987;

int size,numChic;
int answer,minDist,totalDist;
int map[MAX][MAX];
int distances[MAX*MAX][MAX*MAX];

vector <int> indice;
vector <tuple<int,int> > posHouse,posFranchise;

void FindLocations(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(map[r][c]==1) posHouse.push_back(make_tuple(r,c));
			else if(map[r][c]==2) posFranchise.push_back(make_tuple(r,c));
		}
	}
}

void FindDistances(){
	for(int i=0;i<posFranchise.size();i++){
		int fr=get<0>(posFranchise[i]);
		int fc=get<1>(posFranchise[i]);
		for(int j=0;j<posHouse.size();j++){
			int hr=get<0>(posHouse[j]);
			int hc=get<1>(posHouse[j]);
			int dist=abs(fr-hr)+abs(fc-hc);
			distances[i][j]=dist;
		}
	}
}

void PickChickens(){
	for(int i=0;i<posFranchise.size()-numChic;i++) indice.push_back(0);
	for(int i=0;i<numChic;i++) indice.push_back(1);
	do{
		totalDist=0;
		for(int i=0;i<posHouse.size();i++){
			minDist=INF;
			for(int j=0;j<posFranchise.size();j++){
				if(indice[j]==1) minDist=min(minDist,distances[j][i]);
			}
			totalDist+=minDist;
		}
		answer=min(answer,totalDist);
	}while(next_permutation(indice.begin(),indice.end()));
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>numChic;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>map[r][c];
		}
	}
	
	answer=INF;
	
	FindLocations();
	FindDistances();
	PickChickens();
	cout<<answer<<endl;
	
	return 0;
}
