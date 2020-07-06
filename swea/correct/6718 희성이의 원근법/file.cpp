#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

int testcase,answer;
ll dist;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	
	for(int test=1;test<=testcase;test++){
		cin>>dist;
		if(dist>=1000000) answer=5;
		else if(dist>=100000) answer=4;
		else if(dist>=10000) answer=3;
		else if(dist>=1000) answer=2;
		else if(dist>=100) answer=1;
		else answer=0;
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	return 0;
}
