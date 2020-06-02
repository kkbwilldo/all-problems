#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define endl '\n'
using namespace std;

int numCards,limitNum;
int maxVal;

vector <int> cards;
unordered_map <int,int> check;

void AllCases(int depth,int sum){
	if(sum>limitNum) return;
	if(depth==3){
		maxVal=max(maxVal,sum);
		return;
	}
	for(int i=0;i<cards.size();i++){
		int card=cards[i];
		if(check.find(card)==check.end()) continue;
		if(check[card]<=0) continue;
		check[card]--;
		AllCases(depth+1,sum+card);
		check[card]++;
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCards>>limitNum;
	for(int i=0;i<numCards;i++){
		int card;
		cin>>card;
		cards.push_back(card);
		if(check.find(card)==check.end()) check[card]=1;
		else check[card]++;
	}
	
	AllCases(0,0);
	
	cout<<maxVal<<endl;
	
	return 0;
}
