#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int TESTCASE=10;
int size,Start;
string str;

vector <char> numbers;

void Pop(){
	if(Start>=numbers.size()-1) return;
	while(numbers[Start]==numbers[Start+1]){
		numbers.erase(numbers.begin()+Start+1);
		numbers.erase(numbers.begin()+Start);
		Start--;
		if(Start<0) break;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int test=1;test<=TESTCASE;test++){
		cin>>size>>str;
		numbers.clear();
		Start=0;
		for(int i=0;i<size;i++) numbers.push_back(str[i]);
		while(Start<numbers.size()){
			Pop();
			Start++;
		}
		cout<<"#"<<test<<" ";
		for(int i=0;i<numbers.size();i++) cout<<numbers[i];
		cout<<endl;
	}
	
	return 0;
}
