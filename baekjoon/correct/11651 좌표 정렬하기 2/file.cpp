#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define endl '\n'
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
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
	
	int num,x,y;
	vector <pair<int,int> > points;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}
	sort(points.begin(),points.end(),cmp);
	for(int i=0;i<points.size();i++){
		cout<<points[i].first<<" "<<points[i].second<<endl;
	}
	return 0;
}
