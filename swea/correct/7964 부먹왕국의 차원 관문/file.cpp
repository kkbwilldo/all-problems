#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int testcase,answer,numCities,limits;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numCities>>limits;
		vector <int> cities(numCities+1);
		answer=0;
		for(int i=1;i<=numCities;i++) cin>>cities[i];
		int idx=1;
		int numPasses=0;
		while(idx<=numCities){
			if(cities[idx]==0){
				numPasses++;	
			}
			else{
				answer+=numPasses/limits;
				numPasses=0;
			}
			idx++;
		}
		answer+=numPasses/limits;
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
