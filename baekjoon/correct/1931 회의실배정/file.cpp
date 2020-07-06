#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define ll long long
using namespace std;

ll numMeetings,Start,End,answer;
vector <pair<ll,ll> > meetings;

bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b){
	if(a.second<b.second) return true;
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
	
	cin>>numMeetings;
	for(int i=0;i<numMeetings;i++){
		cin>>Start>>End;
		meetings.push_back(make_pair(Start,End));
	}
	sort(meetings.begin(),meetings.end(),cmp);
	ll curStart=meetings[0].first;
	ll curEnd=meetings[0].second;
	answer=1;

	for(int i=1;i<meetings.size();i++){
		ll nStart=meetings[i].first;
		ll nEnd=meetings[i].second;
		if(curEnd<=nStart){
			answer++;
			curStart=nStart;
			curEnd=nEnd;
		}
	}
	cout<<answer<<endl;
	return 0;
}

