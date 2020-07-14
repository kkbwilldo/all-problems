#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=1000000010;

int num,n,gcd;
bool check[MAX];
vector <int> nums,gcds,answer;

int GCD(int a,int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>n;
		nums.push_back(n);
	}
	
	sort(nums.begin(),nums.end());
	
	gcd=nums.front();
	for(int i=1;i<nums.size();i++){
		gcd=GCD(gcd,nums[i]);
	}
	
	for(int i=2;i<=gcd;i++){
		if(gcd%i==0) gcds.push_back(i);
	}
	
	for(int i=0;i<gcds.size();i++){
		int temp=gcds[i];
		if(check[temp]==true) continue;
		while(temp<MAX){
			check[temp]=true;
			temp+=gcds[i];
		}
	}
	
	for(int i=0;i<MAX;i++){
		if(i>=nums.front()) break;
		if(check[i]==true) answer.push_back(i);
	}
	
	for(int i=0;i<answer.size();i++){
		cout<<answer[i];
		if(i!=answer.size()-1) cout<<" ";
	}cout<<endl;
	
	return 0;
}
