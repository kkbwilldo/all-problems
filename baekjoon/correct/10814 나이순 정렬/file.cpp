#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

bool cmp(const tuple<int,string,int> &a,const tuple<int,string,int> &b){
	if(get<0>(a)<get<0>(b)) return true;
	else if(get<0>(a)==get<0>(b)){
		if(get<2>(a)<get<2>(b)) return true;
	}
	return false;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num,age,order;
	string name;
	vector <tuple<int,string,int> > info;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>age>>name;
		info.push_back(make_tuple(age,name,i));
	}
	sort(info.begin(),info.end(),cmp);
	for(int i=0;i<info.size();i++){
		tie(age,name,order)=info[i];
		cout<<age<<" "<<name<<endl;
	}
	return 0;
}
