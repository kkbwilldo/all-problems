#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer,idx;
string str;
vector <string> words;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	getline(cin,str);
	for(int i=0;i<str.size();i++){
		if(str[i]==' '){
			if(i!=0){
				string word=str.substr(idx,i-idx);
				words.push_back(word);
			}
			idx=i+1;
		}
	}
	if(idx<str.size()){
		string word=str.substr(idx,str.size()-idx);
		words.push_back(word);
	}
	answer=words.size();
	cout<<answer<<endl;
	return 0;
}
