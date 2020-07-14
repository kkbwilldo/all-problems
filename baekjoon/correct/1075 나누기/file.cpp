#include <iostream>
#define endl '\n'
using namespace std;

int n,f,answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>n>>f;
	
	n=(n/100)*100;
	for(int i=0;i<100;i++){
		int temp=n+i;
		if(temp%f==0){
			answer=temp%100;
			break;
		}
	}
	if(answer<10) cout<<0;
	cout<<answer<<endl;
	return 0;
}
