#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define ll long long
#define endl '\n'
using namespace std;

ll numBoxes,numRules,numAcorns;
ll Start,End,jump,mid;
ll answer;
vector <tuple<ll,ll,ll> > rules;

ll Count(ll mid){
	ll sum=0;
	for(int i=0;i<numRules;i++){
		ll Start,End,jump;
		tie(Start,End,jump)=rules[i];
		ll minVal=min(End,mid);
		if(minVal>=Start) sum+=((minVal-Start)/jump)+1;
	}
	return sum;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numBoxes>>numRules>>numAcorns;
	for(int i=0;i<numRules;i++){
		cin>>Start>>End>>jump;
		rules.push_back(make_tuple(Start,End,jump));
	}
	
	Start=1;
	End=numBoxes;

	if(Count(Start)==numAcorns) answer=Start;
	else if(Count(End)==numAcorns) answer=End;
	else{
		while(Start<=End){
			mid=(Start+End)/2;
			ll midAcorns=Count(mid);
			if(numAcorns>midAcorns) Start=mid+1;
			else {
				answer=mid;
				End=mid-1;
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}
