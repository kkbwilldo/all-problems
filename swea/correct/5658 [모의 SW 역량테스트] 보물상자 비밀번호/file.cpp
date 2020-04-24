#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#define ull unsigned long long
using namespace std;

ull testcase,len,orderNum;
ull answer;
string word;

vector <string> passwords;

bool cmp(const string &a,const string &b){
	return a>b;
}

ull Conversion(string pwd){
	int size=pwd.size();
	ull sum=0,num=0;
	for(int i=0;i<size;i++){
		if('A'<=pwd[i]&&pwd[i]<='F') num=pwd[i]-'A'+10;
		else num=pwd[i]-'0';
		sum+=pow(16,size-1-i)*num;
	}
	return sum;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		passwords.clear();
		cin>>len>>orderNum>>word;
		int size=len/4;
		for(int i=0;i<size;i++){
			word=word.substr(1,word.size())+word[0];
			for(int j=0;j<4;j++){
				passwords.push_back(word.substr(size*j,size));//여기서 틀림
			}
		}
		sort(passwords.begin(),passwords.end(),cmp);
		passwords.erase(unique(passwords.begin(),passwords.end()),passwords.end()); //중복제거
		
		answer=Conversion(passwords[orderNum-1]);
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	
	return 0;
}
