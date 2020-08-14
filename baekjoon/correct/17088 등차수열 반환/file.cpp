#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define ll long long
#define endl '\n'
using namespace std;

const ll INF=987987987;

ll num,answer,temp;
ll dx[]={-1,0,1};
vector <ll> v;
queue <tuple<ll,ll,ll,ll> > q;

void BFS(){
	while(!q.empty()){
		ll first,second,idx,cnt;
		tie(first,second,idx,cnt)=q.front();
		q.pop();
		ll diff=first-second; 
		if(idx==num){
			answer=min(answer,cnt);
			continue;
		}
		for(int i=0;i<3;i++){
			ll Next=v[idx]+dx[i];
			if(diff!=second-Next) continue;
			ll ncnt=cnt;
			if(i!=1) ncnt++;
			q.push(make_tuple(second,Next,idx+1,ncnt));
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	answer=INF;
	cin>>num;
	if(num<=2){
		answer=0;
		cout<<answer<<endl;
		return 0;
	}
	for(int i=0;i<num;i++){
		cin>>temp;
		v.push_back(temp);
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ll cnt=0;
			if(i!=1) cnt++;
			if(j!=1) cnt++;
			q.push(make_tuple(v[0]+dx[i],v[1]+dx[j],2,cnt));
		}
	}
	
	BFS();
	if(answer==INF) answer=-1;
	cout<<answer<<endl;
	
	return 0;
}
