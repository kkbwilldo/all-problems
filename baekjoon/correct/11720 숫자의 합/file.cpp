#include <iostream>
#include <string>
using namespace std;

int size,answer;
string num;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>num;
	for(int i=0;i<size;i++) answer+=num[i]-'0';
	cout<<answer<<endl;
	return 0;
}
