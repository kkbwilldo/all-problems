#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int MAX=1000;

string A,B;
int LCS[MAX+10][MAX+10];

void PrintLCS(){
	int i=A.size()-1;
	int j=B.size()-1;
	string result="";
	
	while(LCS[i][j]!=0){
		if(LCS[i][j]==LCS[i][j-1]){
			j--;
		}
		else if(LCS[i][j]==LCS[i-1][j]){
			i--;
		}
		else if(LCS[i][j]-1==LCS[i-1][j-1]){
			result=A[i]+result;
			i--;
			j--;
		}
	}
	cout<<result<<endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>A>>B;
	
	A='0'+A;
	B='0'+B;
	
	int sizeA=A.size();
	int sizeB=B.size();
	
	for(int r=0;r<sizeA;r++){
		for(int c=0;c<sizeB;c++){
			if(r==0||c==0){
				LCS[r][c]=0;
				continue;
			}
			// 현재 비교하는 값이 서로 같다면 LCS++;
			if(A[r]==B[c]){
				LCS[r][c] = LCS[r-1][c-1]+1;
			}
			// 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 큰 값을 가져옴
			else{
				LCS[r][c]=max(LCS[r][c-1],LCS[r-1][c]);
			}
		}
	}
	cout<<LCS[sizeA-1][sizeB-1]<<endl;
	PrintLCS();
	return 0;
}
