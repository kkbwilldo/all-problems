#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 5;

int matSize,exp,len;
int num[50];
int mat[MAX][MAX];
int identity[MAX][MAX];
int matrice[50][MAX][MAX];

void ident(){
	int r=0;
	for(int i=0;i<matSize;i++){
		matrice[len-1][r][r]=1;
		r++;
	}
}

void binary(int depth, int exp){
	if(exp==1){
		num[depth]=1;
		return;
	}
	if(exp%2==0){
		num[depth]=0;
		binary(depth+1,exp/2);	
	}
	else{
		num[depth]=1;
		binary(depth+1,exp/2);
	}
}

void conv(int idx, int A[MAX][MAX],int B[MAX][MAX]){
	for(int i=0;i<matSize;i++){
		for(int j=0;j<matSize;j++){
			int sum=0;
			for(int h=0;h<matSize;h++){
				sum+=A[i][h]*B[h][j];
			}
			matrice[idx][i][j]=sum%1000;
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	cin>>matSize>>exp;
	for(int i=0;i<matSize;i++){
		for(int j=0;j<matSize;j++){
			cin>>mat[i][j];
		}
	}
	
	ident();

	memset(num,-1,sizeof(num));
	int temp=exp;
	while(temp!=1){
		len++;
		temp/=2;
	}len++;
	binary(0,exp);
	int pos=len-1;
	while(pos>=0){
		if(pos==len-1) {
			conv(pos,mat,identity);
		}
		else{
			conv(pos,mat)
		
		pos--;
	}
	
	return 0;
}



