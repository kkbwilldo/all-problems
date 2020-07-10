#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

int num,answer;
string str;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		set <char> check;
		vector <char> letters;
		bool isGroup=true;
		cin>>str;
		for(int j=0;j<str.size();j++) letters.push_back(str[j]);
		letters.erase(unique(letters.begin(),letters.end()),letters.end());
		for(int j=0;j<letters.size();j++){
			if(check.find(letters[j])==check.end()) check.insert(letters[j]);
			else{
				isGroup=false;
				break;
			}
		}
		if(isGroup) answer++;
	}
	cout<<answer<<endl;
	return 0;
}
