#include <iostream>
#include <map>
#define endl '\n'
#define ull unsigned long long
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);

	ull a;
	map <ull,ull> table;
	
	for(int i=0;i<10;i++){
		cin>>a;
		table[a%42]=1;
	}
	
	cout<<table.size()<<endl;
	return 0;
}
