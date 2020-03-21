/*
cake 배열을 visit 배열로 사용하므로써
만약 해당 케익 번호에 0이 아닌 숫자가 있으면
해당 케익을 건너뛰며 번호를 배정한다
*/
#include <iostream>
#define endl '\n'
using namespace std;

const int MAX = 1010;

int size,numPeople;
int Start,End;
int expectVal,expectIdx;
int maxVal,maxIdx;
int cake[MAX];
int howManyCake[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>numPeople;
	for(int i=1;i<=numPeople;i++){
		cin>>Start>>End;
		if(expectVal<End-Start+1){
			expectVal=End-Start+1;
			expectIdx=i;
		}
		for(int j=Start;j<=End;j++){
			if(cake[j]!=0) continue;
			cake[j]=i;
			howManyCake[i]++;
		}
	}
	for(int i=1;i<=numPeople;i++){
		if(maxVal<howManyCake[i]){
			maxVal=howManyCake[i];
			maxIdx=i;
		}
	}
	cout<<expectIdx<<endl;
	cout<<maxIdx<<endl;
	return 0;
}
