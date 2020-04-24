#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX=20;
const int INF=987987987;
int testcase,num;
int minVal;
int table[MAX][MAX];

void AllCases(){
	vector <int> indice,team1,team2;
	for(int i=0;i<num/2;i++){
		indice.push_back(1);
		indice.push_back(2);
	}
	sort(indice.begin(),indice.end());
	do{
		team1.clear();
		team2.clear();
		for(int i=0;i<num;i++){
			if(indice[i]==1) team1.push_back(i);
			else team2.push_back(i);
		}
		int sum1,sum2;
		sum1=sum2=0;
		for(int i=0;i<num/2-1;i++){
			for(int j=i+1;j<num/2;j++){
				int idx1=team1[i];
				int idx2=team1[j];
				sum1+=table[idx1][idx2];
				sum1+=table[idx2][idx1];
			}
		}
		for(int i=0;i<num/2-1;i++){
			for(int j=i+1;j<num/2;j++){
				int idx1=team2[i];
				int idx2=team2[j];
				sum2+=table[idx1][idx2];
				sum2+=table[idx2][idx1];
			}
		}
		int result=abs(sum1-sum2);
		minVal=min(minVal,result);
	}while(next_permutation(indice.begin(),indice.end()));
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(table,0,sizeof(table));
		minVal=INF;
		cin>>num;
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				cin>>table[i][j];
			}
		}
		AllCases();
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}
