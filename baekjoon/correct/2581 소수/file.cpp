#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=10010;

int a,b,minVal,sum;
bool firstPrime;
bool notPrimes[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	notPrimes[0]=notPrimes[1]=true;
	for(int i=2;i*i<MAX;i++){
		if(notPrimes[i]==true) continue;
		int temp=i*i;
		while(temp<MAX){
			notPrimes[temp]=true;
			temp+=i;
		}
	}
	
	cin>>a>>b;
	
	for(int i=a;i<=b;i++){
		if(notPrimes[i]==false){
			if(firstPrime==false){
				minVal=i;
				firstPrime=true;
			}
			sum+=i;		
		}
	}
	if(minVal==0) cout<<-1<<endl;
	else cout<<sum<<endl<<minVal<<endl;
	return 0;
}
