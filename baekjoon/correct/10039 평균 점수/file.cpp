#include <iostream>
using namespace std;

int num,answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<5;i++){
		cin>>num;
		num=num>=40?num:40;
		answer+=num;
	}
	answer/=5;
	cout<<answer<<endl;
	return 0;
}
