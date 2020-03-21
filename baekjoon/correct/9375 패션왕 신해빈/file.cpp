#include <iostream>
#include <map>
using namespace std;

long long int testcase,num,cnt;
string item,cate;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num;
		cnt=1;
		map <string,int> categories;
		for(int i=0;i<num;i++){
			cin>>item>>cate;
			if(categories.find(cate)==categories.end()) categories[cate]=1;
			else categories[cate]++;
		}
		map <string,int>::iterator iter;
		for(iter=categories.begin();iter!=categories.end();iter++){
			cnt*=iter->second+1;
		}
		cnt--;
		cout<<cnt<<endl;
	}
	return 0;
}
