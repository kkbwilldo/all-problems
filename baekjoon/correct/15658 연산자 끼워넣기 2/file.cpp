/*
maxVal과 minVal의 초기값을 +,-10억으로 초기화
재귀로 가능한 모든 경우 탐색
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

const int MAX=15;
const ll POS_INF = 1000000001;
const ll NEG_INF = -1000000001;

ll size;
ll maxVal,minVal;
ll numbers[MAX];
ll Plus,Minus,Multiply,Divide;

void Insert(ll depth,ll val,ll Plus,ll Minus,ll Multiply,ll Divide){
	if(depth==size-1){
		maxVal=max(maxVal,val);
		minVal=min(minVal,val);
		return;
	}
	if(Plus>0)
	 Insert(depth+1,val+numbers[depth+1],Plus-1,Minus,Multiply,Divide);
	if(Minus>0)
		Insert(depth+1,val-numbers[depth+1],Plus,Minus-1,Multiply,Divide);
	if(Multiply>0)
		Insert(depth+1,val*numbers[depth+1],Plus,Minus,Multiply-1,Divide);
	if(Divide>0)
		Insert(depth+1,val/numbers[depth+1],Plus,Minus,Multiply,Divide-1);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	for(int i=0;i<size;i++) cin>>numbers[i];
	cin>>Plus>>Minus>>Multiply>>Divide;
	maxVal=NEG_INF;minVal=POS_INF;
	Insert(0,numbers[0],Plus,Minus,Multiply,Divide);
	cout<<maxVal<<endl<<minVal<<endl;
	
	return 0;
} 
