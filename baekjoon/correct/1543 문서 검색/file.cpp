#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int answer;
string a,word;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("input.txt","r",stdin);
	
	getline(cin,a);
	getline(cin,word);
	int idx=0;
	while(idx<a.size()){
		if(a.substr(idx,word.size())==word){
			answer++;
			idx+=word.size();
		}
		else idx++;
	}
	cout<<answer<<endl;
	return 0;
}
