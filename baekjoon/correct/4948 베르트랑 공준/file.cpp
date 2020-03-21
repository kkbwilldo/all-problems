#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 123456*2;
int num;
bool notPrime[MAX];

bool isPrime(int num){
	if(num<=1) return false;
	if(num<=3) return true;
	int temp=2;
	while(temp<sqrt(num)){
		if(num%temp==0) return false;
		temp++;
	}
	return true;
}

void check(){
	notPrime[0]=notPrime[1]=true;
	for(int i=2;i<=MAX;i++){
		if(notPrime[i]) continue;
		if(isPrime(i)){
			int temp = 2*i;
			while(temp<=MAX){
				notPrime[temp]=true;
				temp+=i;
			}
		}
	}
}

int counting(int num){
	int cnt=0;
	for(int i=num+1;i<=2*num;i++){
		if(!notPrime[i]) cnt++;
	}
	return cnt;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	check();
	do{
		cin>>num;
		if(!num) break;
		cout<<counting(num)<<endl;
	}while(1);
	
	return 0;
}



