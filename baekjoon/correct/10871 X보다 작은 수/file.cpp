/*
전체 탐색으로 인풋 값을 받을 때마다 비교하며 출력
*/
#include <iostream>
#define endl '\n'
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num,cmp,Input;
	cin>>num>>cmp;
	for(int i=0;i<num;i++){
		cin>>Input;
		if(Input<cmp) cout<<Input<<" ";
	}
	cout<<endl;
	return 0;
}
