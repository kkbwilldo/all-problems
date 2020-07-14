#include <iostream>
#include <unordered_map>
#include <string>
#define endl '\n'
using namespace std;

const int MAX=200001;

int testcase,numFriends,cnt;
string a,b;

int parents[MAX];
int connects[MAX];

unordered_map <string,int> table;

int GetParent(int a){
	if(parents[a]==a) return a;
	return GetParent(parents[a]);
}

void Union(int a,int b){
	int parentA=GetParent(a);
	int parentB=GetParent(b);
	if(parentA==parentB) return;
	if(parentA<parentB){
		connects[parentA]+=connects[parentB]; // 여기 순서 틀렸다//부모값을 사용하는게 아니므로 상관없다
		connects[parentB]=connects[parentA];
		parents[parentB]=parentA;             // 얘를 먼저 업데이트하면 틀린다
	}
	else{
		connects[parentB]+=connects[parentA]; // 여기도 마찬가지
		connects[parentA]=connects[parentB];	
		parents[parentA]=parentB;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numFriends;
		table.clear();
		for(int i=0;i<MAX;i++) parents[i]=i;
		for(int i=0;i<MAX;i++) connects[i]=1;
		
		int idx=0;
		for(int i=0;i<numFriends;i++){ // 10만
			cin>>a>>b;
			if(table.find(a)==table.end()) table[a]=idx++;
			if(table.find(b)==table.end()) table[b]=idx++;
			Union(table[a],table[b]); // 1
			cnt=connects[GetParent(table[a])]; // parent의 개수를 사용해야 된다!!!
			cout<<cnt<<endl;
		}
	}
	return 0;
}
