#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int a,b;
int sizeA,sizeB;
int idxA,idxB;
vector <int> A,B;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>sizeA>>sizeB;
	for(int i=0;i<sizeA;i++){
		cin>>a;
		A.push_back(a);
	}
	for(int i=0;i<sizeB;i++){
		cin>>b;
		B.push_back(b);
	}
	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	while(idxA<sizeA&&idxB<sizeB){
		if(A[idxA]<B[idxB]) cout<<A[idxA++]<<" ";
		else cout<<B[idxB++]<<" ";
	}
	while(idxA<sizeA) cout<<A[idxA++]<<" ";
	while(idxB<sizeB) cout<<B[idxB++]<<" ";
	cout<<endl;
	return 0;
}

