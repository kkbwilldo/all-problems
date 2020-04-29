#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=23;
const int INF=987987987;

int numPeople,minVal;
int board[MAX][MAX];

void AllCases(){
	minVal=INF;
	for(int numTeam1=1;numTeam1<=numPeople/2;numTeam1++){
		vector <int> indice;
		for(int i=0;i<numPeople-numTeam1;i++) indice.push_back(0);
		for(int i=0;i<numTeam1;i++) indice.push_back(1);
		do{
			vector <int> team1,team2;
			for(int i=0;i<numPeople;i++){
				if(indice[i]) team1.push_back(i);
				else team2.push_back(i);
			}
			int sum1=0,sum2=0;
			for(int i=0;i<team1.size();i++){
				for(int j=i+1;j<team1.size();j++){
					int idx1=team1[i];
					int idx2=team1[j]; // ㅇㅕ기서 team2[j]라고 해서 틀렸다 
					sum1+=board[idx1][idx2]+board[idx2][idx1];
				}
			}
			for(int i=0;i<team2.size();i++){
				for(int j=i+1;j<team2.size();j++){
					int idx1=team2[i];
					int idx2=team2[j];
					sum2+=board[idx1][idx2]+board[idx2][idx1];
				}
			}
			minVal=min(minVal,abs(sum1-sum2));
		}while(next_permutation(indice.begin(),indice.end()));
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPeople;
	for(int r=0;r<numPeople;r++){
		for(int c=0;c<numPeople;c++){
			cin>>board[r][c];
		}
	}
	AllCases();
	cout<<minVal<<endl;
	return 0;
}
