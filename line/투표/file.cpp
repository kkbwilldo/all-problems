#include <iostream>
using namespace std;

const int MAX = 155;

int numPpl;
int Start,End;
int maxVal;
int timeTable[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPpl;
	for(int i=0;i<numPpl;i++){
		cin>>Start>>End;
		for(int j=Start;j<End;j++) timeTable[j]++;
	}
	for(int i=0;i<MAX;i++){
		if(timeTable[i]>maxVal) maxVal=timeTable[i];
	}
	cout<<maxVal<<endl;
	return 0;
}
