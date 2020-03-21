/*
재귀를 이용하여 가능한 모든 경우의 면적을 구함
*/
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int maxVal,area;
int sizes[4];
int indice[4];
bool visited[4];

void allCases(int depth){
	if(depth==4){
		if(indice[0]>=indice[2]&&indice[3]>=indice[1]){
			area=indice[1]*indice[2];
			maxVal=max(maxVal,area);
		}
	}
	else{
		for(int i=0;i<4;i++){
			if(visited[i]) continue;
			visited[i]=true;
			indice[depth]=sizes[i];
			allCases(depth+1);
			visited[i]=false;
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>sizes[0]>>sizes[1]>>sizes[2]>>sizes[3];
	allCases(0);
	cout<<maxVal<<endl;
	return 0;
}
