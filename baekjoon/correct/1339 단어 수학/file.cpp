#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

char alpha[256];

int calc(vector<string> &words, vector<char> &letters, vector<int> &num){
	int letterSize = letters.size();
	int sum=0;
	
	for(int i=0;i<letterSize;i++){
		alpha[letters[i]] = num[i];
	}
	
	for(string s : words){
		int now = 0;
		for(char x : s){
			now = now * 10 + alpha[x];
		}
		sum+=now;
	}
	
	return sum;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	int numWords;
	cin>>numWords;
	
	vector<string> words(numWords);
	vector<char> letters;
	for(int i=0;i<numWords;i++){
		cin>>words[i];
		for(char x : words[i]){
			letters.push_back(x);
		}
	}
	
	sort(letters.begin(),letters.end());
	letters.erase(unique(letters.begin(),letters.end()), letters.end());
	
	int letterSize = letters.size();
	vector<int> num;
	for(int i=9;i>9-letterSize;i--){
		num.push_back(i);
	}
	sort(num.begin(),num.end());
	
	int ans = 0;
	
	do{
		int now = calc(words,letters,num);
		if(ans<now) ans = now;
	} while(next_permutation(num.begin(),num.end()));
	
	cout << ans << '\n';
	
	return 0;
}







