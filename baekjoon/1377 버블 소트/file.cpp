#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=500010;

int num;
int a[MAX];

void BubbleSort(){
	bool change=false;
	for(int i=1;i<num;i++){
		change=false;
		for(int j=1;j<=num-i;j++){
			if(a[j]>a[j+1]){
				change=true;
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
			if(!change){
				cout<<i<<endl;
				break;
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=1;i<=num;i++) cin>>a[i];
	BubbleSort();
	
	return 0;
}
