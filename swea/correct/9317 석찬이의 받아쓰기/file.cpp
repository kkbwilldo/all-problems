#include <iostream>
using namespace std;

int testcase,size,cnt;
string answer,dictation;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>answer>>dictation;
		cnt=0;
		for(int i=0;i<size;i++){
			if(answer[i]==dictation[i]) cnt++;
		}
		cout<<"#"<<test<<" "<<cnt<<endl;
	}
	return 0;
}
