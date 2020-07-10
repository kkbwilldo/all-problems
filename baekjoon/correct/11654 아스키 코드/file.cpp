#include <iostream>
using namespace std;

char letter;
int answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>letter;
	answer=letter;
	cout<<answer<<endl;
	return 0;
}
