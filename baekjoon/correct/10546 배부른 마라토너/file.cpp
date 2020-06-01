#include <iostream>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int numPeople;
string name;
map <string,int> participants,runners;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPeople;
	
	for(int i=0;i<numPeople;i++){
		cin>>name;
		if(participants.find(name)==participants.end()){
			participants[name]=1;
		}
		else{
			participants[name]++;
		}
	}
	
	for(int i=0;i<numPeople-1;i++){
		cin>>name;
		if(runners.find(name)==runners.end()){
			runners[name]=1;
		}
		else{
			runners[name]++;
		}
	}
	
	for(auto iter=participants.begin();iter!=participants.end();iter++){
		name=iter->first;
		if(runners.find(name)==runners.end()){
			cout<<name<<endl;
			break;
		}
		else if(runners[name]!=participants[name]){
			cout<<name<<endl;
			break;
		}
	}
	return 0;
}
