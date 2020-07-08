#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

string num,temp;
int answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	temp=num;
	do{
		int sum=0;
		for(int i=0;i<temp.size();i++){
			sum+=temp[i]-'0';
		}
		sum%=10;
		if(temp.back()=='0') temp=to_string(sum);
		else temp=string(1,temp.back())+to_string(sum);
		answer++;
	}while(num!=temp);
	cout<<answer<<endl;
	return 0;
}
