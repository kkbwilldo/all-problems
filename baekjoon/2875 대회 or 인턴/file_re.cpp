#include <iostream>
#include <algorithm>
using namespace std;

int numG,numB,numI;
int notInTeam,maxVal;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>numG>>numB>>numI;
	maxVal=min(numG/2,numB);
	notInTeam=numG+numB-maxVal*3;
	if(notInTeam<numI){
		maxVal-=(numI-notInTeam)/3+1;
	}
	
	cout<<maxVal<<endl;
	return 0;
}
