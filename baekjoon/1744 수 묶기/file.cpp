#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll size,sum,num;
ll first,second;

vector <ll> pos,neg;

bool cmp(const ll &a, const ll &b){
	if(a>b) return true;
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>num;
		if(num>0) pos.push_back(num);
		else if(num<0) neg.push_back(num);
		else if(num==1) sum++;
	}
	
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end(),cmp);
	
	while(1){
		if(neg.size()>1){
			first=neg.back();
			neg.pop_back();
			second=neg.back();
			neg.pop_back();
			sum+=first*second;
		}
		else if(neg.size()==1){
			first=neg.back();
			neg.pop_back();
			sum+=first;
			break;
		}
		else break;
	}
	
	while(1){
		if(pos.size()>1){
			first=pos.back();
			pos.pop_back();
			second=pos.back();
			pos.pop_back();
			sum+=first*second;
		}
		else if(pos.size()==1){
			first=pos.back();
			pos.pop_back();
			sum+=first;
			break;
		}
		else break;
	}
	
	cout<<sum<<endl;

	return 0;
}
