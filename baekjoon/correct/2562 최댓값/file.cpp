#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int num;
vector <pair<int,int> > pairs;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.first>b.first;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=1;i<=9;i++){
		cin>>num;
		pairs.push_back(make_pair(num,i));
	}
	sort(pairs.begin(),pairs.end(),cmp);
	cout<<pairs.front().first<<endl<<pairs.front().second<<endl;
	return 0;
}
