#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num,number;
vector <int> numbers;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>number;
		numbers.push_back(number);
	}
	sort(numbers.begin(),numbers.end());
	cout<<numbers[num/2]<<endl;
	return 0;
}
