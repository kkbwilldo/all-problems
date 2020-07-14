#include <iostream>
#define endl '\n'
using namespace std;

int x,y,w,h;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>x>>y>>w>>h;
	
	int X=w-x<x?w-x:x;
	int Y=h-y<y?h-y:y;
	int answer=X<Y?X:Y;
	cout<<answer<<endl;
	return 0;
}
