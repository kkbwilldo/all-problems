#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10;

int testcase,num,maxVal,Next;


int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num>>maxVal;
		for(int i=0;i<num-1;i++){
			cin>>Next;
			if(maxVal+Next>=maxVal*Next) maxVal+=Next;
			else maxVal*=Next;
		}
		cout<<"#"<<test<<" "<<maxVal<<'\n';
	}
	return 0;
}
