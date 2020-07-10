/*
2 1 5
1: 0+2->1
2: 1+2->2
3: 2+2->3
4: 3+2

tree-up을 up-slip으로 얼마만에 갈 수 있는지 확인
*/
#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

ll up,slip,tree,days;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>up>>slip>>tree;
	days=(tree-up)/(up-slip);
	if((tree-up)%(up-slip)!=0) days++; // 자잘하게 거리가 남은 경우
	days++; // 마지막 날

	cout<<days<<endl;
	return 0;
}
