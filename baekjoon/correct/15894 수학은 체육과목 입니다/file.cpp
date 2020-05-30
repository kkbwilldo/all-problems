#include <iostream>
#define ll long long
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	ll n,Bottom,Top,Left,Right,numHalves;
	cin>>n;
	Left=Right=Bottom=n;
	Top=1;
	numHalves=n-1;
	cout<<Bottom+Top+Left+Right+numHalves<<endl;
	return 0;
}
