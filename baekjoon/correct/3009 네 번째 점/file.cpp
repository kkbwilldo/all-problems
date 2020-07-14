#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

int r,c;
vector <pair<int,int> > v;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.second>b.second) return true;
	else if(a.second==b.second){
		if(a.first<b.first) return true;
	}
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<3;i++){
		cin>>r>>c;
		v.push_back(make_pair(r,c));
	}
	sort(v.begin(),v.end(),cmp);
	
	pair<int,int> rest;
	if(v[0].second==v[1].second){
		if(v[0].first==v[2].first){
			rest=make_pair(v[1].first,v[2].second);
		}
		else{
			rest=make_pair(v[0].first,v[2].second);
		}
	}
	else if(v[0].first==v[1].first){
		rest=make_pair(v[2].first,v[0].second);
	}
	else{
		rest=make_pair(v[1].first,v[0].second);
	}
	cout<<rest.first<<" "<<rest.second<<endl;
	return 0;
}
