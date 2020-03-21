#include <iostream>
#include <string>
using namespace std;

const int MAX = 60;

int num,len;
string first,other,ans;
bool check[MAX];

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt","r",stdin);
	
	cin>>num;
	cin>>first;
	ans=first;
	len = first.length();
	for(int i=0;i<num-1;i++){
		cin>>other;
		for(int j=0;j<len;j++){
			if(check[j]) continue;
			if(first[j]!=other[j]){
				ans[j]='?';
				check[j]=true;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
