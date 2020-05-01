#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 25;
const int INF = 987987987;

int numPeople;
int ability[MAX][MAX];
int sum1,sum2,minVal;

vector <int> comb;
vector <int> team1;
vector <int> team2;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPeople;
	for(int i=0;i<numPeople;i++){
		for(int j=0;j<numPeople;j++){
			cin>>ability[i][j];
		}
	}
	for(int i=0;i<numPeople/2;i++) comb.push_back(1);
	for(int i=0;i<numPeople/2;i++) comb.push_back(2);
	minVal=INF;
	do{
		team1.clear(); team2.clear();
		for(int i=0;i<numPeople;i++){
			if(comb[i]==1) team1.push_back(i);
			else team2.push_back(i);
		}
		sum1=sum2=0;
		for(int i=0;i<numPeople/2;i++){
			for(int j=0;j<numPeople/2;j++){
				sum1+=ability[team1[i]][team1[j]];
				sum2+=ability[team2[i]][team2[j]];
			}
		}
		minVal=min(minVal,abs(sum1-sum2));
	}while(next_permutation(comb.begin(),comb.end()));
	cout<<minVal<<endl;
	return 0;
}
