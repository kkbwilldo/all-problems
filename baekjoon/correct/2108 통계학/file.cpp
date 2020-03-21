#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 500010;
const int SECOND = 4000*2+1;

int num,avg,mid,mode,rng;
int maxVal,maxIdx;
int numbers[MAX];
int check[SECOND];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>numbers[i];
		if(numbers[i]<0) check[abs(numbers[i])+4000]++;
		else check[numbers[i]]++;
	}
	
	sort(numbers,numbers+num);
	
	double sum = 0;
	for(int i=0;i<num;i++){
		sum+=numbers[i];
	}
	sum/=num;
	avg=round(sum);
	mid = numbers[num/2];
	rng = numbers[num-1]-numbers[0];
	
	vector<int> indice;
	
	for(int i=0;i<SECOND;i++){
		if(!check[i]) continue;
		if(maxVal<check[i]){
			maxVal = check[i];
			maxIdx = i;
		}
	}
	
	for(int i=0;i<SECOND;i++){
		if(!check[i]) continue;
		if(check[i]==maxVal){
			int a=i;
			if(a>4000){a-=4000;a*=-1;}
			indice.push_back(a);
		}
	}
	
	sort(indice.begin(),indice.end());
	
	mode = indice[0];
	if(indice.size()>1) mode = indice[1];
	
	cout<<avg<<endl<<mid<<endl<<mode<<endl<<rng<<endl;
	
	return 0;
}
