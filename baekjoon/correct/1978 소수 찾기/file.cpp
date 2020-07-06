#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

const int MAX=1050;

int numNum,num,answer;
int notPrimes[MAX+1];

void SetPrimes(){
	notPrimes[0]=notPrimes[1]=1;
	for(int i=2;i<=sqrt(MAX);i++){
		if(notPrimes[i]==0){
			int temp=i*i;
			while(temp<=MAX){
				notPrimes[temp]=1;
				temp+=i;
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	SetPrimes();
	cin>>numNum;
	for(int i=0;i<numNum;i++){
		cin>>num;
		if(notPrimes[num]==0) answer++;
	}
	cout<<answer<<endl;
	return 0;
}
