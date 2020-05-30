#include <iostream>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int h,m;
	cin>>h>>m;
	m-=45;
	if(m<0){
		h-=1;
		m+=60;
	}
	if(h<0) h+=24;
	cout<<h<<" "<<m<<endl;
	return 0;
}
