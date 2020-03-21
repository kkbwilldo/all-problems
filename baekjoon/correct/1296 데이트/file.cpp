#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX=52;
const int MOD=100;

int numGirls;
int val,maxVal,maxIdx;
int manL,manO,manV,manE;
int girlL,girlO,girlV,girlE;
int L,O,V,E;
string Man;
string names[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>Man;
	for(int i=0;i<Man.size();i++){
		if(Man[i]=='L') manL++;
		else if(Man[i]=='O') manO++;
		else if(Man[i]=='V') manV++;
		else if(Man[i]=='E') manE++;
	}
	cin>>numGirls;
	for(int i=0;i<numGirls;i++) cin>>names[i];
	
	sort(names,names+numGirls);
	
	for(int i=0;i<numGirls;i++){
		girlL=girlO=girlV=girlE=0;
		for(int j=0;j<names[i].size();j++){
			if(names[i][j]=='L') girlL++;
			else if(names[i][j]=='O') girlO++;
			else if(names[i][j]=='V') girlV++;
			else if(names[i][j]=='E') girlE++;
		}
		L=girlL+manL;
		O=girlO+manO;
		V=girlV+manV;
		E=girlE+manE;
		val=((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%MOD;
		if(maxVal<val){
			maxVal=val;
			maxIdx=i;
		}
	}
	cout<<names[maxIdx]<<endl;
	return 0;
}
