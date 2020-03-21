/*
가장 작은 수부터 탐색 & 가장 큰 수부터 탐색 2가지 방법으로 해결

isOkay() 함수는 설정한 숫자가 부등호에 맞는 값인지 확인하는 함수로
숫자 배열 NUMBERS의 인덱스 depth-1값과 인덱스 depth 값에 대해서
부등호가 맞으면 true를 반환한다.

inequal() 함수는 재귀 함수로
최소값을 구할 땐 숫자배열에 0~9순으로 입력
최대값을 구할 땐 숫자배열에 9~0순으로 입력하여
부등호가 옳게되면 바로 종료하여 더 이상 탐색하지 않는다

*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;

int numStr,numNum;
int NUMBERS[MAX];
char STRINGS[MAX];
bool isOff,isMin;
bool check[MAX];

bool isOkay(int depth){
	if(depth==0) return true;
	else{
		if(STRINGS[depth-1]=='>'){
			if(NUMBERS[depth-1]>NUMBERS[depth]) return true;
		}
		else{
			if(NUMBERS[depth-1]<NUMBERS[depth]) return true;
		}
	}
	return false;
}

void inequal(int depth){
	if(isOff) return;
	if(depth==numNum){
		for(int i=0;i<numNum;i++) cout<<NUMBERS[i];
		cout<<endl;
		isOff=true;
		return;
	}
	else{
		if(isMin){
			for(int i=0;i<=9;i++){
				if(!check[i]){
					check[i]=true;
					NUMBERS[depth]=i;
					if(isOkay(depth)) inequal(depth+1);
					check[i]=false;
				}
			}
		}
		else{
			for(int i=9;i>=0;i--){
				if(!check[i]){
					check[i]=true;
					NUMBERS[depth]=i;
					if(isOkay(depth)) inequal(depth+1);
					check[i]=false;
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
	
	cin>>numStr;
	numNum=numStr+1;
	for(int i=0;i<numStr;i++) cin>>STRINGS[i];
	
	isOff=false;
	memset(NUMBERS,0,sizeof(NUMBERS));
	memset(check,0,sizeof(check));
	isMin=false;
	inequal(0);
	isOff=false;
	memset(NUMBERS,0,sizeof(NUMBERS));
	memset(check,0,sizeof(check));
	isMin=true;
	inequal(0);
	
	return 0;
}
