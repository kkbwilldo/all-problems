#include <iostream>
using namespace std;

int numGirls,numBoys,numInterns;
int maxVal,girls,boys;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>numGirls>>numBoys>>numInterns;
	for(int i=1;i<numInterns;i++){
		girls=numGirls-i;
		if(girls<=0) break;
		boys=numBoys-(numInterns-i);
		girls/=2;
		if(girls>=boys){
			if(maxVal<boys) maxVal=boys;
		}
		else{
			if(maxVal<girls) maxVal=girls;
		}
	}
	cout<<maxVal<<endl;
	return 0;
}
