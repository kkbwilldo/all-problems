/*
테스트 케이스 2*10^5개 1초의 제한이므로, for loop을 쓸 수 없다
따라서 입력값을 바로 계산하여 출력한다
규칙성을 찾은 것은 아래와 같다
*/
#include <iostream>
#define ll unsigned long long
#define endl '\n'

using namespace std;

ll testcase,num,small,big;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cout<<"#"<<test<<" ";
		cin>>num>>small>>big;
		if(small>big) cout<<0<<endl;
		else if(small==big) cout<<1<<endl;
		else{
			if(num==1) cout<<0<<endl;
			else if(num==2) cout<<1<<endl;
			else cout<<(num-3)*(big-small)+(big-small+1)<<endl;
		} 
	}
	return 0;
}
