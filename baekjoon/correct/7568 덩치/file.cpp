#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=60;

int numPeople,weight,height;
int aw,ah,ai,bw,bh,bi;
vector <int> dungchi(MAX,1);
vector <tuple<int,int, int> > info;

bool cmp(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
	if(get<0>(a)<get<0>(b)) return true;
	else if(get<0>(a)==get<0>(b)){
		if(get<1>(a)<get<1>(b)) return true;
	}
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPeople;
	
	for(int i=0;i<numPeople;i++){
		cin>>weight>>height;
		info.push_back(make_tuple(weight,height,i));
	}
	
	sort(info.begin(),info.end(),cmp);
	
	for(int i=0;i<info.size()-1;i++){
		tie(aw,ah,ai)=info[i];
		for(int j=i+1;j<info.size();j++){
			tie(bw,bh,bi)=info[j];
			if(aw<bw&&ah<bh) dungchi[ai]++;
		}
	}
	
	for(int i=0;i<numPeople;i++){
		cout<<dungchi[i];
		if(i!=numPeople-1) cout<<" ";	
	}
	cout<<endl;
	return 0;
}
