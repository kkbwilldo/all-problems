#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

int num;
string word;
vector <string> words;

void PushUnique(string word){
	int size=word.size();
	for(int i=0;i<words.size();i++){
		for(int j=0;j<size;j++){
			if(words[i]==word) return;
			word+=word.front();
			word.erase(word.begin());
		}
	}
	words.push_back(word);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>word;
		PushUnique(word);
	}
	cout<<words.size()<<endl;
	return 0;
}

