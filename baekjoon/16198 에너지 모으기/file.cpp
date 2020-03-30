#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numBeads,bead,val;
int maxIdx,maxVal;
vector <int> beads;

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
	while(beads.size()>2){
		maxVal=0;
		for(int i=1;i<beads.size()-1;i++){
			if(maxVal<beads[i-1]*beads[i+1]){
				maxVal=beads[i-1]*beads[i+1];
				maxIdx=i;
			}
		}
		val+=maxVal;
		beads.erase(beads.begin()+maxIdx);
	}
	cout<<val<<endl;
	return 0;
}
