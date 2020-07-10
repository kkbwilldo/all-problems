#include <iostream>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int answer;
string str;
map <char,int> table;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	table['A']=table['B']=table['C']=3;
	table['D']=table['E']=table['F']=4;
	table['G']=table['H']=table['I']=5;
	table['J']=table['K']=table['L']=6;
	table['M']=table['N']=table['O']=7;
	table['P']=table['Q']=table['R']=table['S']=8;
	table['T']=table['U']=table['V']=9;
	table['W']=table['X']=table['Y']=table['Z']=10;
	cin>>str;
	for(int i=0;i<str.size();i++){
		answer+=table[str[i]];
	}
	cout<<answer<<endl;
	return 0;
}
