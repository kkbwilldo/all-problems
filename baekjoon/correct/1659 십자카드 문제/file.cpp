#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

int number,answer;
vector <int> numbers,allCases;

int GetNum(vector <int> a){
	int num=0;
	for(int i=0;i<4;i++) num+=a[i]*pow(10,3-i);
	return num;
}

int GetSerial(vector <int> a){
	int minVal=987987987;
	for(int i=0;i<4;i++){
		int num=GetNum(a);
		minVal=min(minVal,num);
		a.push_back(a.front());
		a.erase(a.begin());
	}
	return minVal;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<4;i++){
		cin>>number;
		numbers.push_back(number);
	}

	int serialNum=GetSerial(numbers);
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				for(int l=1;l<=9;l++){
					vector <int> temp={i,j,k,l};
					int serial=GetSerial(temp);
					allCases.push_back(serial);
				}					
			}
		}
	}
	sort(allCases.begin(),allCases.end());
	allCases.erase(unique(allCases.begin(),allCases.end()),allCases.end());
	
	for(int i=0;i<allCases.size();i++){
		if(allCases[i]==serialNum){
			answer=i+1;
			break;
		}
	}

	cout<<answer<<endl;
	return 0;
}
