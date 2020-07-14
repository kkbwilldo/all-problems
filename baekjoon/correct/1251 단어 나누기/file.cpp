#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

string str,first,second,third,answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>str;
	answer="";
	for(int i=0;i<str.size();i++) answer+='z';
	for(int i=0;i<str.size()-2;i++){
		for(int j=i+1;j<str.size()-1;j++){
			for(int h=j+1;h<str.size();h++){
				string temp="";
				first=str.substr(0,j);
				second=str.substr(j,h-j);
				third=str.substr(h,str.size()-h);
				for(int k=first.size()-1;k>=0;k--) temp+=string(1,first[k]);
				for(int k=second.size()-1;k>=0;k--) temp+=string(1,second[k]);
				for(int k=third.size()-1;k>=0;k--) temp+=string(1,third[k]);
				if(temp<answer){
					answer=temp;
				}
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}
