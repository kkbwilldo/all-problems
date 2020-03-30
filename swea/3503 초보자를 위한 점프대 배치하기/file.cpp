// 삼성: 초보자를 위한 점프대 배치하기

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 10010;

int testcase,num;
int mid,back,forw;
int maxVal;
int numbers[MAX],result[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	
	for(int test=1;test<=testcase;test++){
		// 배열 초기화 
		memset(numbers,0,sizeof(numbers));
		memset(result,0,sizeof(result));
		
		cin>>num;
		
		for(int i=0;i<num;i++) cin>>numbers[i];
		sort(numbers,numbers+num);    // 입력 정렬
		
		back=forw=mid=num/2;          // 중앙 위치 설정 
		result[mid]=numbers[0];
		//좌우로 작은 것 두기
		for(int i=1;i<=mid;i++){
			result[--back]=numbers[2*i-1];
			if(2*i<num) result[++forw]=numbers[2*i];
		}

		maxVal=abs(result[num-1]-result[0]);
		for(int i=0;i<num-1;i++){
			maxVal=max(maxVal,abs(result[i]-result[i+1]));
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
