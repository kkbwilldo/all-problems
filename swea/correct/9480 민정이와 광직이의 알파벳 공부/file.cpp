/*
nC1~nCn의 조합을 모두 구한 후 모든 단어를 1개의 문자열로 만든다.
만든 문자열에서 중복 알파벳을 제거한다.
그 후 모든 알파벳이 포함되어 있는지 확인하고 모두 포함하면 setCount를 증가시킨다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;

const int MAX = 20;

int testcase,num,setCount;
int indice[MAX];
string words[MAX];

void wordSet(int depth){
	if(depth==num){
		vector <char> letters;
		for(int i=0;i<num;i++){
			if(indice[i]==1){
				for(int j=0;j<words[i].size();j++){
					letters.push_back(words[i][j]);
				}
			}
		}
		sort(letters.begin(),letters.end());
		letters.erase(unique(letters.begin(),letters.end()),letters.end());
		if(letters.size()==26) setCount++;
	}
	else{
		indice[depth]=0;
		wordSet(depth+1);
		indice[depth]=1;
		wordSet(depth+1);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(indice,0,sizeof(indice));
		//memset(words,0,sizeof(words));
		setCount=0;
		cin>>num;
		for(int i=0;i<num;i++) cin>>words[i];
		wordSet(0);
		cout<<"#"<<test<<" "<<setCount<<endl;
	}
	return 0;
}
