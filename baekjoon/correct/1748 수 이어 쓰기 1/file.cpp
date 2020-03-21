// 수 이어 쓰기 1

#include <iostream>
#include <cmath>
using namespace std;

int num,ans,digit;

void howMany(int num){
	digit = 1;
	while(num/10!=0){
		digit++;
		num/=10;
	}
}

void calc(int num){
	howMany(num);
	int temp = digit;
	while(temp>0){
		int base = pow(10,temp-1);
		int ceilling = digit == temp ? num : pow(10,temp)-1;
		ans+=(ceilling-base+1)*temp;
		temp--;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	calc(num);
	cout<<ans<<endl;
	return 0;
}
