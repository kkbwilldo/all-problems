#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int numBeads,bead,answer;
vector <int> beads,indices;

void AllCases(vector <int> &b,int sum){
	if(b.size()==2){
		answer=max(answer,sum);
		return;
	}
	for(int i=1;i<=b.size()-2;i++){
		int energy=b[i];
		int side=b[i-1]*b[i+1];
		b.erase(b.begin()+i);
		AllCases(b,sum+side);
		b.insert(b.begin()+i,energy);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);

	cin>>numBeads;
	for(int i=0;i<numBeads;i++){
		cin>>bead;
		beads.push_back(bead);
	}
	AllCases(beads,0);
	cout<<answer<<endl;
	return 0;
}
