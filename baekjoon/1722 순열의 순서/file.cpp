#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int num,type;
	cin>>num>>type;
	if(type==1){
		int order;
		cin>>order;
		vector<int> seq(num);
		for(int i=0;i<num;i++) seq[i]=i+1;
		for(int i=0;i<order-1;i++) next_permutation(seq.begin(),seq.end());
		for(int i=0;i<num;i++) cout<<seq[i]<<" ";
		cout<<endl;
	}
	else{
		vector<int> numbers(num);
		vector<int> seq(num);
		for(int i=0;i<num;i++) {
			cin>>numbers[i];
			seq[i]=i+1;
		}
		int idx=1;
		while(1){
			bool same = true;
			for(int i=num-1;i>=0;i--){
				if(numbers[i]!=seq[i]){
					same = false;
					break;
				}
			}
			if(same){
				cout<<idx<<endl;
				break;
			}
			idx++;
			next_permutation(seq.begin(),seq.end());
		}
	}
	return 0;
}
