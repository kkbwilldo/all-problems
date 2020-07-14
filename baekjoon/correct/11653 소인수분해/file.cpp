#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=10000010;

int num;
bool notPrimes[MAX];
vector <int> primes;

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
	for(int i=0;i<MAX;i++){
		if(notPrimes[i]==false) primes.push_back(i);
	}
	cin>>num;
	for(int i=0;i<primes.size();i++){
		if(num/primes[i]==0) break;
		while(num%primes[i]==0){
			cout<<primes[i]<<endl;
			num/=primes[i];
		}
	}
	return 0;
}
