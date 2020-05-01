#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int NUM=13;
const int MIN=1000000000;
const int MAX=-1000000000;

int num;
int numPlus,numMinus,numMultiply,numDivide;
int minVal,maxVal;
int numbers[NUM];
char symbols[NUM];

void init(){
	minVal=MIN;
	maxVal=MAX;
}

int calc(){
	int sum=numbers[0];
	for(int i=0;i<num-1;i++){
		if(symbols[i]=='+') sum+=numbers[i+1];
		else if(symbols[i]=='-') sum-=numbers[i+1];
		else if(symbols[i]=='*') sum*=numbers[i+1];
		else if(symbols[i]=='/') sum/=numbers[i+1];
	}
	return sum;
}

void insert(int depth,int _numPlus,int _numMinus,int _numMultiply,int _numDivide){
	if(depth==num-1){
		int result=calc();
		minVal=min(minVal,result);
		maxVal=max(maxVal,result);
		return;
	}
	if(_numPlus>0){
		symbols[depth]='+';
		insert(depth+1,_numPlus-1,_numMinus,_numMultiply,_numDivide);
	}
	if(_numMinus>0){
		symbols[depth]='-';
		insert(depth+1,_numPlus,_numMinus-1,_numMultiply,_numDivide);
	}
	if(_numMultiply>0){
		symbols[depth]='*';
		insert(depth+1,_numPlus,_numMinus,_numMultiply-1,_numDivide);
	}
	if(_numDivide>0){
		symbols[depth]='/';
		insert(depth+1,_numPlus,_numMinus,_numMultiply,_numDivide-1);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>numbers[i];
	}
	cin>>numPlus>>numMinus>>numMultiply>>numDivide;
	init();
	insert(0,numPlus,numMinus,numMultiply,numDivide);
	cout<<maxVal<<endl<<minVal<<endl;
	return 0;
}

