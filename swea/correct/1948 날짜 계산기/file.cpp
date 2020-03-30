#include <iostream>
using namespace std;

const int MAX = 12;

int testcase,maxVal;
int firstM,firstD,secondM,secondD;
int days[MAX+1];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	days[1]=31;days[2]=28;days[3]=31;days[4]=30;days[5]=31;days[6]=30;
	days[7]=31;days[8]=31;days[9]=30;days[10]=31;days[11]=30;days[12]=31;
	for(int test=1;test<=testcase;test++){
		cin>>firstM>>firstD>>secondM>>secondD;
		maxVal=0;
		for(int i=firstM;i<=secondM;i++) maxVal+=days[i];
		maxVal-=(firstD-1)+(days[secondM]-secondD);
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
