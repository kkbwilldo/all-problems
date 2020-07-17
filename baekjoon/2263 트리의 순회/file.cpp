#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

int num,n,depth,root;
vector <int> In,Post;

int GetDepth(int num){
	int depth=1;
	int nodes=0;
	while(1){
		nodes+=pow(2,depth-1);
		if(num<=nodes) return depth;
		depth++;
	}
}

void inorder(int node){
	
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>n;
		In.push_back(n);
		if(i==0) root=n;
	}
	for(int i=0;i<num;i++){
		cin>>n;
		Post.push_back(n);
	}
	
	depth=GetDepth(num);
	
	return 0;
}
