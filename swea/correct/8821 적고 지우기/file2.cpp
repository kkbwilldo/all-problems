/*
set 자료구조를 사용하여 방문처리
만약 set에 특정 수가 있으면 set에서 제거
없으면 set에 추가
set의 크기를 출력
*/
#include <iostream>
#include <set>
using namespace std;

int testcase,target,size;
string num;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num;
		size=num.size();
		set <int> visited;
		for(int i=0;i<size;i++){
			target=num[i]-'0';
			if(visited.find(target)==visited.end()) visited.insert(target);
			else visited.erase(target);
		}
		cout<<"#"<<test<<" "<<visited.size()<<endl;
	}
	
	return 0;
}
