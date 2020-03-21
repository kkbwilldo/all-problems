/*
테스트 케이스 = 10^5, N=10^9이므로 for loop을 돌 수 없다
따라서 입력 값을 바로 계산해야하므로 규칙성을 찾는다
길이 9까지 손으로 규칙석으로 찾은 결과 1,4,9라는 규칙성이 나와 
((size-1)/2)^2를 제출해봤더니 맞았다
*/
#include <iostream>
#define ll unsigned long long
#define endl '\n'
using namespace std;

ll testcase,size;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size;
		cout<<"#"<<test<<" "<<((size-1)/2)*((size-1)/2)<<endl;
	}
	
	return 0;
}
