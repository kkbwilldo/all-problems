/*
map 자료구조를 이용하여 문제해결
map에 책의 이름과 책의 개수를 인자로 넣고
새로운 책이 들어올 때마다 책의 개수를 업데이트 한다
*/
#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	map<string,int> Rank;
	map<string,int>::iterator iter;
	int numBooks,maxVal;
	string name,top;	
	
	cin>>numBooks;
	for(int i=0;i<numBooks;i++){
		cin>>name;
		if(Rank.find(name)==Rank.end()) Rank[name]=1;
		else Rank[name]++;
	}
	
	for(iter=Rank.begin();iter!=Rank.end();iter++){
		if(maxVal < iter->second){
			maxVal=iter->second;
			top=iter->first;
		}
	}
	
	cout<<top<<endl;
	return 0;
}
