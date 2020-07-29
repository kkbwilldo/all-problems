#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define endl '\n'
using namespace std;

ll numProbs,Left,Right,Limit,answer;
ll difficulty;
vector <ll> difficulties;

void AllCases(){
	for(int pick=2;pick<=numProbs;pick++){
		vector <int> indices;
		for(int i=0;i<numProbs-pick;i++) indices.push_back(0);
		for(int i=0;i<pick;i++) indices.push_back(1);
		do{
			ll sum=0;
			ll first=-1,second=-1;
			for(int i=0;i<indices.size();i++){
				if(indices[i]==0) continue;
				if(first==-1) first=difficulties[i];
				//else if(first!=-1&&second==-1) second=difficulties[i]; 여기 틀림
				second=difficulties[i];
				sum+=difficulties[i];
			}
			
			if((Left<=sum&&sum<=Right)&&(second-first>=Limit)) answer++;
		}while(next_permutation(indices.begin(),indices.end()));
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numProbs>>Left>>Right>>Limit;
	for(int i=0;i<numProbs;i++){
		cin>>difficulty;
		difficulties.push_back(difficulty);
	}
	sort(difficulties.begin(),difficulties.end());
	
	AllCases();
	cout<<answer<<endl;
	return 0;
}
