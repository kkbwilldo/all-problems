#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

long long int MAX;

bool isPrime(long long int num){
	if(num<=1) return false;
	else if(num<=3) return true;
	else{
		long long int temp = 2;
		while(temp<sqrt(num)){
			if(num%temp==0) return false;
			temp++;
		}
		return true;
	}
}

void check(int END,bool *notPrime){
	notPrime[0]=notPrime[1]=true;
	for(long long int i=2;i<=END;i++){
		if(isPrime(i)){
			MAX = i;
			long long int temp = 2*i;
			while(temp<=END){
				notPrime[temp] = true;
				temp+=i;
			}
		}
	}
}


bool isPalin(long long int num){
	if(num/10==0) return true;
	else{
		string str = to_string(num);
		int len = str.size();
		for(int i=0;i<len/2;i++){
			if(str[i]!=str[len-1-i]) return false;
		}
		return true;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int a,b;
	cin>>a>>b;
	bool notPrime[b+1];
	memset(notPrime,0,sizeof(notPrime));
	check(b,notPrime);
	if(b>=MAX) b = MAX;
	for(int i=a;i<=b;i++){
		if(isPalin(i)){
			if(isPrime(i)){
				cout<<i<<endl;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
