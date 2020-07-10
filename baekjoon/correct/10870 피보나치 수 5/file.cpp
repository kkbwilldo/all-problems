#include <iostream>
#define endl '\n'
using namespace std;

int num,answer;

int Fibo(int n){
	if(n==0) return 0;
	else if(n==1) return 1;
	else return Fibo(n-1)+Fibo(n-2);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	answer=Fibo(num);
	cout<<answer<<endl;
	
	return 0;
}
