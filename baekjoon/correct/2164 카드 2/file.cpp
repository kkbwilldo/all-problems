#include <iostream>
#include <queue>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num;
	cin>>num;
	queue <int> numbers;
	for(int i=1;i<=num;i++) numbers.push(i);
	while(numbers.size()>1){
		numbers.pop();
		numbers.push(numbers.front());
		numbers.pop();
	}
	cout<<numbers.front()<<endl;
	return 0;
}
