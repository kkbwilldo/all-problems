#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

string str;
vector <int> answer(26);

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>str;
	for(int i=0;i<answer.size();i++) answer[i]=-1;
	for(int i=0;i<str.size();i++){
		int idx=str[i]-'a';
		if(answer[idx]==-1) answer[idx]=i;
	}
	for(int i=0;i<answer.size();i++){
		cout<<answer[i];
		if(i!=answer.size()-1) cout<<" ";
	}
	cout<<endl;
	
	return 0;
}
