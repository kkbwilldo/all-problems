#include <iostream>
#include <string>
#include <map>
#define endl '\n'
#define ull unsigned long long
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);

	ull a,b,c,result;
	string str;
	map <char,int> table;
	cin>>a>>b>>c;
	result=a*b*c;
	str=to_string(result);
	
	for(int i=0;i<10;i++) table[i+'0']=0;
	
	for(int i=0;i<str.size();i++) table[str[i]]++;
	
	for(auto iter=table.begin();iter!=table.end();iter++){
		cout<<iter->second<<endl;
	}
	return 0;
}
