// 좋은 수열

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int MAX = 90;

int num,sum;
int numbers[MAX];
int check[MAX];

bool isGood(int depth){
	if(depth==0||depth==1) return true; // 비어있거나 1개 채워진 수열은 좋은 수열
	int lenMax = depth/2;      // 2개 수열의 최대 길이
	for(int len=1;len<=lenMax;len++){
		memset(check,0,sizeof(check));
		sum=0;
		for(int i=0;i<len;i++){
			if(numbers[i]==numbers[i+len]) check[i]=1; // 같음을 표시
			sum+=check[i];
		}
		if(sum==len) return false; // 두 개 수열이 같음
		for(int i=0;i<depth-2*len;i++){ // 1칸씩 수열을 옆으로 이동 
			sum-=check[i];         // 맨 앞 숫자 뺀다
			if(numbers[i+len]==numbers[i+len+len]) check[i+len]=1;
			sum+=check[i+len];
			if(sum==len) return false;
		}
	}
	return true;
}

void good(int depth){
	if(!isGood(depth)) return; // 좋은 수열이 아님
	if(depth==num){						 // 좋은 수열로 수열 만들어짐
		for(int i=0;i<depth;i++){
			cout<<numbers[i];
		}
		cout<<endl;
		exit(0);
	}
	for(int i=1;i<=3;i++){     // 숫자 채우기 
		numbers[depth]=i;
		good(depth+1);           // 재귀함수
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	good(0);
	return 0;
}
