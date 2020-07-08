#include <iostream>
#define endl '\n'
using namespace std;

int numCalls,call;
int Youngsik,Minsik;

int main ()
{
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCalls;
	for(int i=0;i<numCalls;i++){
		cin>>call;
		Minsik+=(call/60)*15;
		Minsik+=15;
		Youngsik+=(call/30)*10;
		Youngsik+=10;
	}
	
	
	if(Youngsik<Minsik) cout<<"Y "<<Youngsik<<endl;
	else if(Youngsik>Minsik) cout<<"M "<<Minsik<<endl;
	else cout<<"Y M "<<Minsik<<endl;
	
	return 0;
}
