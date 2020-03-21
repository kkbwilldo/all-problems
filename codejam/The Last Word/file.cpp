/*
입력 문자열 str과 정답 문자열 word를 만든다.
word[0]과 str[i]를 비교하여 str[i]가 word[0]보다 크거나 작으면 str[i]를 앞에 붙인다 
*/
#include <iostream>
#include <string>
using namespace std;

int testcase;
int size;
string str,word;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>str;
		size=str.size();
		word=str[0];
		for(int i=1;i<=size-1;i++){
			if(str[i]>=word[0]) word=str[i]+word;
			else word=word+str[i];
		}
		cout<<"Case #"<<test<<": "<<word<<endl;
	}
	return 0;
}
