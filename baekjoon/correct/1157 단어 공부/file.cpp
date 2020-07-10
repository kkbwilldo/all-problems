#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>
#define endl '\n'
using namespace std;

string str;
vector <pair<char,int> > v;
map <char,int> m;

char GetUpper(char letter){
	char result=letter;
	if('a'<=letter&&letter<='z'){
		result=letter-'a'+'A';
	}
	return result;
}

bool cmp(const pair<char,int> &a,const pair<char,int> &b){
	return a.second>b.second;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>str;
	for(int i=0;i<str.size();i++){
		char letter=GetUpper(str[i]);
		if(m.find(letter)==m.end()) m[letter]=1;
		else m[letter]++;
	}
	for(auto iter=m.begin();iter!=m.end();iter++){
		char letter=iter->first;
		int num=iter->second;
		v.push_back(make_pair(letter,num));
	}
	
	sort(v.begin(),v.end(),cmp);
	if(v.size()==1){
		cout<<v[0].first<<endl;
	}
	else{
		if(v[0].second!=v[1].second) cout<<v[0].first<<endl;
		else cout<<"?"<<endl;
	}
	return 0;
}
