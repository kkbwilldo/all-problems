#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int numCards,card,numQueries,query;
int answer;

vector <int> cards;

int binSearch(int q){
	int Start=0;
	int End=cards.size()-1;
	if(cards[Start]==q||cards[End]==q) return 1;
	if(cards[Start]==cards[End]){
		if(cards[Start]==q) return 1;
		else return 0;
	}
	else if(cards[Start]>q) return 0;
	else if(cards[End]<q) return 0;
	while(Start+1<End){
		int mid=(Start+End)/2;
		if(cards[mid]==q) return 1;
		else if(cards[mid]<q) Start=mid;
		else End=mid;
	}
	return 0;
}

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numCards;
	for(int i=0;i<numCards;i++){
		cin>>card;
		cards.push_back(card);		
	}
	sort(cards.begin(),cards.end());
	
	cin>>numQueries;
	for(int i=0;i<numQueries;i++){
		cin>>query;
		answer=binSearch(query);
		cout<<answer<<" ";
	}
	cout<<endl;
	return 0;
}
