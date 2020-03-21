/*
map 자료구조를 이용하여 모든 대문자를 카이사르 표에 맞게 매핑한다.
입력 문자열을 키값으로 사용하여 문자를 출력한다.
*/
#include <iostream>
#include <map>
#include <string>
#define endl '\n'
using namespace std;

string caesar;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>caesar;
	
	map <char,char> Table;
	
	for(int i=0;i<23;i++){
		char Key = 'A'+(i+3);
		char Letter = 'A'+i;
		Table[Key]=Letter;
	}
	Table['A']='X';Table['B']='Y';Table['C']='Z';
	
	for(int i=0;i<caesar.size();i++) cout<<Table[caesar[i]];
	cout<<endl;
	return 0;
}
