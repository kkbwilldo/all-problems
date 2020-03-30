#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct point{
	int x,y;
};
int testcase,x,y;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.first<b.first) return true;
	else if(a.first==b.first){
		if(a.second<b.second) return true;
		else return false;
	}
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	
	for(int test=1;test<=testcase;test++){
		vector <pair<int,int> > pos;
		int cnt=0;
		for(int i=0;i<4;i++){
			cin>>x>>y;
			pos.push_back(make_pair(x,y));
		}
		sort(pos.begin(),pos.end(),cmp);
		point ll,ul,lr,ur;
		ll.x=pos[0].first;ll.y=pos[0].second;
		ul.x=pos[1].first;ul.y=pos[1].second;
		lr.x=pos[2].first;lr.y=pos[2].second;
		ur.x=pos[3].first;ur.y=pos[3].second;
		
		cout<<"ll x,y: "<<ll.x<<","<<ll.y<<endl;
		cout<<"ul x,y: "<<ul.x<<","<<ul.y<<endl;
		cout<<"lr x,y: "<<lr.x<<","<<lr.y<<endl;
		cout<<"ur x,y: "<<ur.x<<","<<ur.y<<endl;
		
		if((abs(ll.x-ul.x)==abs(ll.x-lr.x))&&(abs(ll.y-ul.y)==abs(ll.y-lr.y))) cnt++;
		if((abs(ul.x-ur.x)==abs(ul.x-ll.x))&&(abs(ul.y-ur.y)==abs(ul.y-ll.y))) cnt++;
		if((abs(ur.x-ul.x)==abs(ur.x-lr.x))&&(abs(ur.y-ul.y)==abs(ur.y-lr.y))) cnt++;
		if((abs(lr.x-ll.x)==abs(lr.x-ur.x))&&(abs(lr.y-ll.y)==abs(lr.y-ur.y))) cnt++;
		if((abs(ll.x-ur.x)==abs(ul.x-lr.x))&&(abs(ll.y-ur.y)==abs(ul.y-lr.y))) cnt++;
		if(cnt==5) cout<<1<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}
