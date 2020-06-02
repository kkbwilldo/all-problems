#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num,number;
	vector <int> numbers;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>number;
		numbers.push_back(number);
	}
	sort(numbers.begin(),numbers.end());
	for(int i=0;i<numbers.size();i++) cout<<numbers[i]<<endl;
	return 0;
}
