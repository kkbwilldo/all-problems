#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numTrees,numFlowers;
int sum,maxVal;
vector <int> Flowers;

int Calc(int Start,int End){
	int mul=1;
	for(int i=Start;i<=End;i++) mul*=Flowers[i];
	return mul;
}

void AllCases(){
	for(int i=0;i<numTrees-3;i++){
		for(int j=i+1;j<numTrees-2;j++){
			for(int k=j+1;k<numTrees-1;k++){
				for(int l=k+1;l<numTrees;l++){
					sum=Calc(0,i)+Calc(i+1,j)+Calc(j+1,k)+Calc(k+1,l);
					maxVal=max(maxVal,sum);
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numTrees;
	for(int i=0;i<numTrees;i++){
		cin>>numFlowers;
		Flowers.push_back(numFlowers);
	}
	AllCases();
	
	cout<<maxVal<<endl;	
	
	return 0;
}
