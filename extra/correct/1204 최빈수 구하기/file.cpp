#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
using namespace std;

const int MAX=1000;

int testcase,test,score;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.first>b.first) return true;
	else if(a.first==b.first){
		if(a.second>b.second) return true;
		else return false;
	}
	return false;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		cin>>test;
		map <int,int> freq;
		for(int j=0;j<MAX;j++){
			cin>>score;
			if(freq.find(score)==freq.end()) freq[score]=1;
			else freq[score]++;
		}
		vector <pair<int,int> > info;
		for(auto iter=freq.begin();iter!=freq.end();iter++){
			info.push_back(make_pair(iter->second,iter->first));
		}
		sort(info.begin(),info.end(),cmp);
		cout<<"#"<<test<<" "<<info[0].second<<endl;
	}
	
	return 0;
}
