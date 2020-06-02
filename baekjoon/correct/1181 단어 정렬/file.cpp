#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

bool cmp(const pair<string,int> &a,const pair<string,int> &b){
	if(a.second<b.second) return true;
	else if(a.second==b.second){
		if(a.first<b.first) return true;
	}
	return false;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num;
	string word;
	vector <pair<string,int> > pairs;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>word;
		pairs.push_back(make_pair(word,word.size()));
	}
	sort(pairs.begin(),pairs.end(),cmp);
	pairs.erase(unique(pairs.begin(),pairs.end()),pairs.end());
	for(int i=0;i<pairs.size();i++) cout<<pairs[i].first<<endl;
	return 0;
}
