#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=110;

int n,m,k;
int a[MAX][MAX],b[MAX][MAX],answer[MAX][MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>n>>m;
	for(int r=0;r<n;r++){
		for(int c=0;c<m;c++){
			cin>>a[r][c];
		}
	}
	cin>>m>>k;
	for(int r=0;r<m;r++){
		for(int c=0;c<k;c++){
			cin>>b[r][c];
		}
	}
	for(int r=0;r<n;r++){
		for(int c=0;c<k;c++){
			int sum=0;
			for(int h=0;h<m;h++){
				sum+=a[r][h]*b[h][c];
			}
			answer[r][c]=sum;
		}	
	}
	for(int r=0;r<n;r++){
		for(int c=0;c<k;c++){
			cout<<answer[r][c];
			if(c!=k-1) cout<<" ";
		}cout<<endl;
	}
	return 0;
}
