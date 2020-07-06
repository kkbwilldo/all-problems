#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define endl '\n'
using namespace std;

const ll INF=987987987987;

ll num,diff,number,minVal;
ll Start,End,size;

vector <ll> numbers;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	minVal=INF;
	cin>>num>>diff;
	for(ll i=0;i<num;i++){
		cin>>number;
		numbers.push_back(number);
	}
	
	sort(numbers.begin(),numbers.end());
	Start=0;End=1;
	size=numbers.size();
	while(Start<size&&End<size){
		if(numbers[End]-numbers[Start]<diff) End++;
		else if(numbers[End]-numbers[Start]>diff){
			minVal=min(minVal,numbers[End]-numbers[Start]);
			Start++;
		}
		else{
			minVal=min(minVal,numbers[End]-numbers[Start]);
			break;
		}
	}
	cout<<minVal<<endl;
	return 0;
}
