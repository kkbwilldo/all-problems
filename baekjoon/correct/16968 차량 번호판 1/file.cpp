#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int answer;
string type;

void AllCases(int depth,string num){
	if(depth==type.size()){
		answer++;
		return;
	}
	if(type[depth]=='c'){
		for(int i=0;i<26;i++){
			char letter='a'+i;
			if(num.back()==letter) continue;
			AllCases(depth+1,num+letter);
		}
	}
	else if(type[depth]=='d'){
		for(int i=0;i<10;i++){
			char letter='0'+i;
			if(num.back()==letter) continue;
			AllCases(depth+1,num+letter);
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>type;
	
	AllCases(0,"");
	
	cout<<answer<<endl;
	return 0;
}
