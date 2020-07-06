// B를 2진수로 바꾼다
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

ll size,exponent;
int matrice[40][5][5];

int[][5] Multiply(int a[][5],int b[][5]){
	int result[5][5];
	memset(result,0,sizeof(result));
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			for(int h=0;h<size;h++){
				result[r][c]+=a[r][c]*b[c][r];
			}
		}
	}
	return result;
}

void Print(int a[][5]){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cout<<a[r][c]<<" ";
		}cout<<endl;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>exponent;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>matrice[0][r][c];
		}
	}
	
	int val[5][5];
	val=Multiply(matrice[0],matrice[0]);
	
	Print(val);
	return 0;
}
