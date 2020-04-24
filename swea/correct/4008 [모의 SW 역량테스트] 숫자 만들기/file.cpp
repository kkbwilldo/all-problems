#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define plus _plus
#define minus _minus
#define multiply _multiply
#define divide _divide
using namespace std;

const ll MAX=15;
const ll NEG_INF=-100000001;
const ll POS_INF=100000001;

char symbols[MAX];
ll testcase,maxVal,minVal;
ll num;
ll plus,minus,multiply,divide;
ll numbers[MAX];

ll GetResult(){
	ll sum=numbers[0];
	for(int i=0;i<num-1;i++){
		if(symbols[i]=='+') sum=sum+numbers[i+1];
		else if(symbols[i]=='-') sum=sum-numbers[i+1];
		else if(symbols[i]=='*') sum=sum*numbers[i+1];
		else if(symbols[i]=='/') sum=sum/numbers[i+1];
	}
	return sum;
}

void AllCases(ll depth,ll plus,ll minus,ll multiply,ll divide){
	if(depth==num-1){
		ll result=GetResult();
		maxVal=max(maxVal,result);
		minVal=min(minVal,result);
		return;
	}
	if(plus>0){
		symbols[depth]='+';
		AllCases(depth+1,plus-1,minus,multiply,divide);
	}
	if(minus>0){
		symbols[depth]='-';
		AllCases(depth+1,plus,minus-1,multiply,divide);
	}
	if(multiply>0){
		symbols[depth]='*';
		AllCases(depth+1,plus,minus,multiply-1,divide);
	}
	if(divide>0){
		symbols[depth]='/';
		AllCases(depth+1,plus,minus,multiply,divide-1);
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(numbers,0,sizeof(numbers));
		memset(symbols,0,sizeof(symbols));
		cin>>num;
		minVal=POS_INF;
		maxVal=NEG_INF;
		cin>>plus>>minus>>multiply>>divide;
		for(int i=0;i<num;i++) cin>>numbers[i];
		AllCases(0,plus,minus,multiply,divide);
		cout<<"#"<<test<<" "<<maxVal-minVal<<endl;
	}
	return 0;
}

