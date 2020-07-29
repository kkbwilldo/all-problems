#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX=55;

int numWords,numPicks,maxSize;
string word;
vector <char> sizes[MAX];
deque <char> answer; 
unordered_map <char,int> table;
unordered_map <int,char> Reverse;
unordered_set <char> check;

bool cmp(const char &a,const char &b){
	return table[a]<table[b];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("input.txt","r",stdin);

	for(int i=0;i<10;i++){
		char idx='0'+i;
		table[idx]=i;
		Reverse[i]=idx;
	}
	for(int i=0;i<26;i++){
		char idx='A'+i;
		table[idx]=i+10;
		Reverse[i+10]=idx;
	}

	cin>>numWords;
	for(int i=0;i<numWords;i++){
		cin>>word;
		int size=word.size();
		maxSize=max(maxSize,size);
		for(int idx=size;idx>0;idx--){
			sizes[idx].push_back(word[size-1-(idx-1)]);
		}
	}
	cin>>numPicks;
	for(int i=0;i<=maxSize;i++){
		if(!sizes[i].empty()){
			sort(sizes[i].begin(),sizes[i].end(),cmp);
		}
	}

	int idx=0;
	int level=maxSize;
	while(numPicks>0){
		if(level<=0) break;
		if(sizes[level].empty()){
			level--;
			continue;
		}
		if(idx<sizes[level].size()){
			if(check.find(sizes[level][idx])==check.end()){
				check.insert(sizes[level][idx]);
				idx++;
				numPicks--;
			}
			else{
				idx++;
			}
		}
		else{
			idx=0;
			level--;
		}
	}
	
	int carry=0;
	for(int i=1;i<MAX;i++){
		int sum=carry;
		for(int j=0;j<sizes[i].size();j++){
			char letter=sizes[i][j];
			if(check.find(letter)!=check.end()){
				sum+=table['Z'];
			}
			else{
				sum+=table[letter];
			}
		}
		answer.push_front(Reverse[sum%36]);
		carry=sum/36;
	}
	while(answer.front()=='0') answer.pop_front();
	if(answer.empty()) answer.push_front('0');
	while(!answer.empty()){
		cout<<answer.front();
		answer.pop_front();
	}cout<<endl;
	return 0;
}

