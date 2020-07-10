#include <iostream>
#include <cmath>
#define ll long long
#define endl '\n'
using namespace std;

ll answer,roomNum;
ll Start,End;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>roomNum;
	
	//1번 껍질: 1
	//2번 껍질: 1+1~1+6
	//3번 껍질: 7+1~7+12
	//4번 껍질: 19+1~19+18
	//5번 껍질: 37+1~37+24
	Start=0;End=1;
	answer=1;
	while(!(Start<=roomNum&&roomNum<=End)){
		int NextStart=End+1;
		int NextEnd=End+answer*6;
		Start=NextStart;
		End=NextEnd;
		answer++;
	}
	cout<<answer<<endl;
	return 0;
}
