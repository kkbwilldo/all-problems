#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int numWords,size,maxVal;
char AlphabetsMap[256];
string word;

vector <char> letters;
vector <int> vals;
vector <string> words;

void Unique(){
	sort(letters.begin(),letters.end());
	letters.erase(unique(letters.begin(),letters.end()),letters.end());
	size=letters.size();
}

void Assign(){
	for(int i=9;i>=9-size+1;i--) vals.push_back(i);
	sort(vals.begin(),vals.end());
}

int Calc(string word){
	for(int i=0;i<size;i++) AlphabetsMap[letters[i]]=vals[i];
	int sum=0;
	for(int i=0;i<word.size();i++) sum=sum*10+AlphabetsMap[word[i]];
	return sum;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numWords;
	for(int i=0;i<numWords;i++){
		cin>>word;
		words.push_back(word);
		for(int j=0;j<word.size();j++){
			letters.push_back(word[j]);
		}
	}
	
	Unique();
	Assign();
	do{
		int sum=0;
		for(int i=0;i<words.size();i++) sum+=Calc(words[i]);
		maxVal=max(maxVal,sum);
	}while(next_permutation(vals.begin(),vals.end()));
	cout<<maxVal<<endl;
	return 0;
}
