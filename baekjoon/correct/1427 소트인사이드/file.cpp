#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

bool cmp(const int &a,const int &b){
	return a>b;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	string num;
	vector <int> number;
	cin>>num;
	for(int i=0;i<num.size();i++){
		number.push_back(num[i]-'0');
	}
	sort(number.begin(),number.end(),cmp);
	for(int i=0;i<number.size();i++) cout<<number[i];
	cout<<endl;
	return 0;
}
