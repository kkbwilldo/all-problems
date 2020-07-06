#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int testcase,numHouses,numPlants;

void AllCases(){
	vector <int> indice;
	for(int i=0;i<numHouses-numPlants;i++) indice.push_back(0);
	for(int i=0;i<numPlants;i++) indice.push_back(1);
	do{
		
	}while(next_permutation(indice.begin(),indice.end()));
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	
	for(int test=1;test<=testcase;test++){
		cin>>numHouses>>numPlants;
		
	}
	return 0;
}
