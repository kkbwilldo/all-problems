#include <iostream>
#define endl '\n'
#define ll long long
using namespace std;

ll fingerIdx,numCnts,answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>fingerIdx>>numCnts;
	
	if(fingerIdx==1&&numCnts==0){
		cout<<answer<<endl;
		return 0;
	}
	
	if(fingerIdx==1||fingerIdx==5) answer=fingerIdx+8*numCnts-1;
	else if(fingerIdx==2){
		numCnts++;
		if(numCnts%2==0) answer=0+8*(numCnts/2)-1;
		else answer=2+8*(numCnts/2)-1;
	}
	else if(fingerIdx==3){
		answer=3+4*numCnts-1;
	}
	else if(fingerIdx==4){
		numCnts++;
		if(numCnts%2==0) answer=-2+8*(numCnts/2)-1;
		else answer=4+8*(numCnts/2)-1;
	}
	cout<<answer<<endl;
	return 0;
}
