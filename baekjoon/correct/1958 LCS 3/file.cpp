#include <iostream>
#include <string>
using namespace std;

const int MAX=110;

string str1,str2,str3;
int size1,size2,size3;
int DP[MAX][MAX][MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>str1>>str2>>str3;
	size1=str1.size();
	size2=str2.size();
	size3=str3.size();
	
	for(int i=1;i<=size1;i++){
		for(int j=1;j<=size2;j++){
			for(int k=1;k<=size3;k++){
				if(str1[i-1]==str2[j-1]&&str2[j-1]==str3[k-1]){
					DP[i][j][k]=DP[i-1][j-1][k-1]+1;
				}
				else{
					DP[i][j][k]=max(DP[i-1][j][k],max(DP[i][j-1][k],DP[i][j][k-1]));
				}
			}
		}
	}
	cout<<DP[size1][size2][size3]<<endl;
	return 0;
}
