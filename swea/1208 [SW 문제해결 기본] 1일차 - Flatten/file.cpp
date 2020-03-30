#include <iostream>
#include <algorithm>
using namespace std;

const int MAX =100;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int test=1;test<=10;test++){
		int dump;
		int heights[MAX];
		cin>>dump;
		for(int i=0;i<MAX;i++) cin>>heights[i];
		for(int i=0;i<dump;i++){
			sort(heights,heights+MAX);
			heights[MAX-1]--;
			heights[0]++;
		}
		sort(heights,heights+MAX);
		cout<<"#"<<test<<" "<<heights[99]-heights[0]<<endl;
	}
	return 0;
}
