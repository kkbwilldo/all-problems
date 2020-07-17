#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=510;
const int INF=987987987;

int numMatrices,r,c,answer;
int DP[MAX][MAX];
vector <pair<int,int> > info;

int GetMin(int Start,int End){
	if(Start==End) return 0;
	if(DP[Start][End]!=0) return DP[Start][End];
	int minVal=INF;
	for(int i=Start;i<End;i++){
		int val=GetMin(Start,i)+GetMin(i+1,End);
		val+=info[Start].first*info[i].second*info[End].second;
		minVal=min(minVal,val);
	}
	return DP[Start][End]=minVal;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numMatrices;
	for(int i=0;i<numMatrices;i++){
		cin>>r>>c;
		info.push_back(make_pair(r,c));
	}
	answer=GetMin(0,numMatrices-1);
	cout<<answer<<endl;
	
	return 0;
}
