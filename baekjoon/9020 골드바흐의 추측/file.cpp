#include <iostream>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=10001;
const int INF=987987987;

int testcase,num,Start,End,sum,minVal;
bool notPrimes[MAX];
pair<int,int> answer;
vector <int> primes;


int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	notPrimes[0]=notPrimes[1]=true;
	for(int i=2;i*i<MAX;i++){
		if(notPrimes[i]==true) continue;
		primes.push_back(i);
		int temp=i*i;
		while(temp<MAX){
			notPrimes[temp]=true;
			temp+=i;
		}
	}
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num;
		Start=sum=0;
		End=1;
		minVal=INF;
		while(Start<primes.size()&&End<primes.size()){
			sum+=primes[End];
			if(sum==num){
				if(minVal>primes[End])
			}
		}
	}
	
	return 0;
}
