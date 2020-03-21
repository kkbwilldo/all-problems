#include <iostream>
#define endl "\n"
using namespace std;

const int MAX = 110;
const long long MOD = 1000000000;

int len,sum;
long long DP[MAX][12];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>len;
	for(int digit=1;digit<=9;digit++) DP[1][digit]=1;
	
	for(int i=2;i<=len;i++){
		for(int digit=0;digit<=9;digit++){
			if(digit==0) DP[i][0]=DP[i-1][1]%MOD;
			else if(digit==9) DP[i][9]=DP[i-1][8]%MOD;
			else DP[i][digit]=(DP[i-1][digit+1]+DP[i-1][digit-1])%MOD;
		}
	}
	for(int digit=0;digit<=9;digit++){
		sum+=DP[len][digit];
		sum%=MOD;
	}
	cout<<sum%MOD<<endl;
	return 0;
}
