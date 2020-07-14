#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int num,idx,curNum,r,c;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	curNum=666;
	while(idx<num){
		string strNum=to_string(curNum);
		if(strNum.find("666")!=-1) idx++;
		curNum++;
	}
	cout<<curNum-1<<endl;
	return 0;
}
