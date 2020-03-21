#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int INF = 987987987;

int numStrings,numBrands;
int pack,each;
int minPack,minEach,minTotal;
int minVal;
int minCost,cost1,cost2,cost3;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numStrings>>numBrands;
	minVal=minPack=minEach=minTotal=INF;
	
	for(int i=0;i<numBrands;i++){
		cin>>pack>>each;
		if(pack<minPack) minPack=pack;
		if(each<minEach) minEach=each;
	}
	cost1=(numStrings/6)*minPack+(numStrings%6)*minEach;
	cost2=numStrings*minEach;
	cost3=(numStrings/6)*minPack;
	if(numStrings%6!=0) cost3+=minPack;
	minCost=min(cost1,cost2);
	minCost=min(minCost,cost3);
	minVal=min(minVal,minCost);
	cout<<minVal<<endl;
	return 0;
}
		
