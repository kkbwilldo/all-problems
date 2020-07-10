#include <iostream>
#include <vector>
#define ull unsigned long long
#define endl '\n'
using namespace std;

const ull MAX=10000001;

ull a,b,answer;
ull notPrimes[MAX];
vector <ull> primes;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	notPrimes[0]=notPrimes[1]=1;
	
	for(ull i=2;i<MAX;i++){
		notPrimes[i]=i;
	}
	
	for(ull i=2;i*i<MAX;i++){
		if(notPrimes[i]!=i) continue;
		ull temp=i*i;
		while(temp<MAX){
			notPrimes[temp]=1;
			temp+=i;
		}
	}
	
	for(ull i=2;i<MAX;i++){
		if(notPrimes[i]==i) primes.push_back(i);
	}
	
	cin>>a>>b;

	for(ull i=0;i<primes.size();i++){
		ull num=primes[i];
		while(primes[i]<=b/num){
			if(a<=primes[i]*num){
				answer++;
			}
			num*=primes[i];
		}
	}
	cout<<answer<<endl;
	return 0;
}
