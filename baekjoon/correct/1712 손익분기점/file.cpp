#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

ll Fixed,variable,price,answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>Fixed>>variable>>price;
	//price*x>fixed+variable*x
	//(price-variable)*x>fixed
	//x>fixed/(price-variable)
	//answer>1000/(170-70)
	if(price-variable<=0) answer=-1;
	else{
		answer=Fixed/(price-variable);
		answer++;
	}
	cout<<answer<<endl;
	return 0;
}
