#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int a,b,c;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>a>>b>>c;
	while(!(a==0&&b==0&&c==0)){
		vector <int> sizes={a,b,c};
		sort(sizes.begin(),sizes.end());
		a=sizes[0];b=sizes[1];c=sizes[2];
		if(c*c==a*a+b*b) cout<<"right"<<endl;
		else cout<<"wrong"<<endl;
		cin>>a>>b>>c;
	}
	return 0;
}
