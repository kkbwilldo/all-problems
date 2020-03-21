/*
전체 탐색으로 가장 높은 값을 업데이트 하면서 업데이트 횟수를 카운트
*/
#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=52;

int numTrophys;
int Left,LeftMax,Right,RightMax;
int trophys[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numTrophys;
	for(int i=0;i<numTrophys;i++) cin>>trophys[i];
	for(int i=0;i<numTrophys;i++){
		if(LeftMax<trophys[i]){
			LeftMax=trophys[i];
			Left++;
		}
		if(RightMax<trophys[numTrophys-1-i]){
			RightMax=trophys[numTrophys-1-i];
			Right++;
		}
	}
	cout<<Left<<endl<<Right<<endl;
	
	return 0;
}
