#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#define ll long long
#define endl '\n'
using namespace std;

const ll MAX=1000010;

ll num;
int DP[MAX];
bool notPrimes[MAX];

int GetNext(int num){
	string str=to_string(num);
	int sum=0;
	for(int i=0;i<str.size();i++){
		sum+=pow(str[i]-'0',2);
	}
	return sum;
}

int Check(int num, set <int> visited){
	if(DP[num]!=0) return DP[num];
	visited.insert(num);
	int Next=GetNext(num);
	if(Next==1) return DP[num]=1;
	else if(visited.find(Next)!=visited.end()) return DP[num]=-1;
	else return DP[num]=Check(Next,visited);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	
	notPrimes[0]=notPrimes[1]=true;
	for(int i=2;i<sqrt(MAX);i++){
		int temp=i*i;
		while(temp<MAX){
			notPrimes[temp]=true;
			temp+=i;
		}
	}
	
	for(int i=2;i<=num;i++){
		if(!notPrimes[i]){
			set <int> visited;
			if(Check(i,visited)==1) cout<<i<<endl;
		}
	}
	
	return 0;
}
