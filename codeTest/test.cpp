#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> comb;

int main ()
{
	for(int i=0;i<9;i++) comb.push_back(0);
	comb.push_back(3);comb.push_back(3);
	do{
		for(int i=0;i<comb.size();i++) cout<<comb[i]<<" ";
		cout<<endl;
	}while(next_permutation(comb.begin(),comb.end()));
	return 0;
}
