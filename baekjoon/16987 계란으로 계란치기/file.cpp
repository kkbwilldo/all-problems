#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int numEggs,durability,weight;
vector <int> d,w;

int main ()
{
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numEggs;
	for(int i=0;i<numEggs;i++){
		cin>>durability>>weight;
		d.push_back(durability);
		w.push_back(weight);
	}
	
	for(int i=0;i<numEggs;i++){
		int curD=d[i];
		int curW=w[i];
		
	}
	
	
	return 0;
}
