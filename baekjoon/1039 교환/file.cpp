#include <iostream>
#include <algorithm>
#include <tuple>
#include <set>
#define endl '\n'
using namespace std;

int numSwaps,size,answer;
string str;
set <pair<string,int> > visited;

string Swap(string str,int idx1,int idx2){
	string result=str;
	swap(result[idx1],result[idx2]);
	return result;
}

void Search(int depth,string number){
	if(depth==numSwaps){
		if(number[0]!='0'){
			int result=stoi(number);
			answer=max(answer,result);
		}
		return;
	}
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(i==0&&number[j]=='0') continue;
			string Next=Swap(number,i,j);
			if(visited.find(make_pair(Next,depth))!=visited.end()) continue;
			visited.insert(make_pair(Next,depth));
			Search(depth+1,Next);
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>str>>numSwaps;
	size=str.size();
	if(size==1||(size==2&&str.back()=='0')){
		cout<<-1<<endl;
		exit(0);
	}
	
	
	
	
	//Search(0,str);
	cout<<answer<<endl;
	
	return 0;
}
