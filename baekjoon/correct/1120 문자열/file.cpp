#include <iostream>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	string a,b;
	cin>>a>>b;
	int lenA = a.size();
	int lenB = b.size();
	int minVal = 51;
	for(int i=0;i<=lenB-lenA;i++){
		int cnt = 0;
		for(int j=0;j<lenA;j++){
			if(a[j]!=b[i+j]) cnt++;
		}
		if(minVal>cnt) minVal = cnt;
	}
	
	cout<<minVal<<endl;
	
	return 0;
}
