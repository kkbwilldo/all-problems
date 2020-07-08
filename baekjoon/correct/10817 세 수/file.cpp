#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int num;
vector <int> nums;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<3;i++){
		cin>>num;
		nums.push_back(num);
	}
	sort(nums.begin(),nums.end());
	cout<<nums[1]<<endl;
	return 0;
}
