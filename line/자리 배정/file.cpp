#include <iostream>
using namespace std;

int seat[20010];
int maxVal;
int n,cnt=1;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>seat[i];
	int i;
	for(i=0;i<n;i++){
		if(seat[i]==1) break;
	}
	for(i=i+1;i<n;i++){
		if(seat[i]==0) cnt++;
		else{
			int temp=cnt%2?cnt/2+1:cnt/2;
			if(maxVal<temp) maxVal=temp;
			cnt=0;
		}
	}
	
	cnt=0;
	for(int i=0;i<n;i++){
		if(seat[i]==0) cnt++;
		else break;
	}
	if(maxVal<cnt) maxVal=cnt;
	
	cnt=0;
	for(int i=n-1;i>=0;i--){
		if(seat[i]==0) cnt++;
		else break;
	}
	if(maxVal<cnt) maxVal=cnt;
	
	cout<<maxVal<<endl;

	return 0;
}
