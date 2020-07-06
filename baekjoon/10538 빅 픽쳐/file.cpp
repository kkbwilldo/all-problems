#include <iostream>
#include <vector>
#include <string>
#define ll long long 
#define endl '\n'
using namespace std;

ll mod = 2147483647;
int base = 2;
int rowSmall,rowBig,colSmall,colBig;

ll Calc(vector <int> &a, int begin,int end){
	ll answer=0;
	for(int i=begin;i<end;i++) answer=(answer*base+a[i])%mod;
	return answer;
}

vector <int> Convert(string &s){
	int size=s.size();
	vector <int> answer(size,0);
	for(int i=0;i<size;i++){
		if(s[i]=='o') answer[i]=1;
	}
	return answer;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>rowSmall>>colSmall>>rowBig>>colBig;
	vector <vector<int> > small(rowSmall),big(rowBig);
	
	for(int i=0;i<rowSmall;i++){
		string temp;
		cin>>temp;
		small[i]=Convert(temp);
	}
	
	for(int i=0;i<rowBig;i++){
		string temp;
		cin>>temp;
		big[i]=Convert(temp);
	}
	
	ll powCol=1;
	for(int i=0;i<colSmall-1;i++) powCol=(powCol*base)%mod;
	ll baseRow=(powCol*base)%mod;
	ll powRow=1;
	for(int i=0;i<rowSmall-1;i++) powRow=(powRow*baseRow)%mod;
	ll hashSmall=0;
	for(int i=0;i<rowSmall;i++) hashSmall=(hashSmall*baseRow+Calc(small[i],0,colSmall))%mod;
	vector <vector<ll> > hashCol(rowBig,vector<ll>(colBig));
	{
		auto &d=hashCol;
		for(int i=0;i<rowBig;i++){
			d[i][0]=Calc(big[i],0,colSmall);
			for(int j=1;j<=colBig-colSmall;j++){
				d[i][j]=d[i][j-1]-(big[i][j-1]*powCol)%mod;
				d[i][j]=(d[i][j]+mod)%mod;
				d[i][j]=((d[i][j]*base)%mod+big[i][j+colSmall-1])%mod;
			}
		}
	}
	
	vector <vector<ll> > hashRect(rowBig,vector<ll>(colBig));
	{
		auto &d=hashRect;
		for(int j=0;j<=colBig-colSmall;j++){
			d[0][j]=0;
			for(int i=0;i<rowSmall;i++) d[0][j]=(d[0][j]*baseRow+hashCol[i][j])%mod;
			for(int i=1;i<=rowBig-rowSmall;i++){
				d[i][j]=d[i-1][j]-(hashCol[i-1][j]*powRow)%mod;
				d[i][j]=(d[i][j]+mod)%mod;
				d[i][j]=((d[i][j]*baseRow)%mod+hashCol[i+rowSmall-1][j])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=rowBig-rowSmall;i++){
		for(int j=0;j<=colBig-colSmall;j++){
			if(hashSmall==hashRect[i][j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
