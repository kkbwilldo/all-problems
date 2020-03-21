
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;

int numDays,maxVal;
int days[MAX],pays[MAX];

void Counseling(int dayIdx,int totalPay){
	if(dayIdx>=numDays+1){
		maxVal=max(maxVal,totalPay);
		return;
	}
	if(dayIdx+days[dayIdx]<=numDays+1)
		Counseling(dayIdx+days[dayIdx],totalPay+pays[dayIdx]);
	if(dayIdx+1<=numDays+1)
		Counseling(dayIdx+1,totalPay);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numDays;
	for(int i=1;i<=numDays;i++) cin>>days[i]>>pays[i];
	Counseling(1,0);
	cout<<maxVal<<endl;
	
	
	return 0;
}

