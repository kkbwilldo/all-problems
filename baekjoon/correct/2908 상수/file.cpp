#include <iostream>
#include <string>
using namespace std;

string a,b;
bool A,B;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]>b[i]){
			A=true;
			break;
		}
		else if(a[i]<b[i]){
			B=true;
			break;
		}
	}
	if(A){
		for(int i=a.size()-1;i>=0;i--) cout<<a[i];
		cout<<endl;
	}
	else if(B){
		for(int i=a.size()-1;i>=0;i--) cout<<b[i];
		cout<<endl;
	}
	return 0;
}
