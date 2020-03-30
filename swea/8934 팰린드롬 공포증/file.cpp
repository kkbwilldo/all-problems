#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int testcase,size,Left,Right;
string str;
bool isPalin;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>str;
		size=str.size();
		isPalin=false;
		for(int i=0;i<size;i++){
			Left=i-1;
			Right=i+1;
			if(Left<0||Right>=size) continue;
			if(str[Left]==str[Right]){
				isPalin=true;
				break;
			}
		}
		if(isPalin) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}	
	return 0;
}
