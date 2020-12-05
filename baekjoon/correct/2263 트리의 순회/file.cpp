/*
inorder  : left root right
postorder: left right root
*/
#include <iostream>
#define endl '\n'
using namespace std;

const int MAX=100000;

int numNodes,node,idx;
int inorder[MAX+10],postorder[MAX+10],preorder[MAX+10];
int inorder_idx[MAX+10];

// 하나의 서브트리에서의 inStart,inEnd,postStart,postEnd 입력
void Preorder(int inStart,int inEnd,int postStart,int postEnd){
	
	if(inStart>inEnd || postStart>postEnd) return;	
	
	int root = postorder[postEnd];
	
	preorder[idx++]=root;
	
	int root_idx=inorder_idx[root];
	int numLefts=root_idx-inStart;
	int numRights=postEnd-root_idx;
	// left sub
	Preorder(inStart,root_idx-1,postStart,postStart+numLefts-1);
	// right sub
	Preorder(root_idx+1,inEnd,postStart+numLefts,postEnd-1);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numNodes;
	for(int i=0;i<numNodes;i++){
		cin>>inorder[i];
	}
	
	// 인오더에서 나오는 각 숫자의 위치
	for(int i=0;i<numNodes;i++){
		inorder_idx[inorder[i]]=i;
	}
	
	
	for(int i=0;i<numNodes;i++){
		cin>>postorder[i];
	}
	
	Preorder(0,numNodes-1,0,numNodes-1);
	
	for(int i=0;i<idx;i++){
		cout<<preorder[i]<<" ";
	}cout<<endl;
	
	return 0;
}
