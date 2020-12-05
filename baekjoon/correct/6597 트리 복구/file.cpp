#include <iostream>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;

const int MAX=30;

int Size;
int inorder_idx[MAX];
string preorder,inorder,postorder;

void Postorder(int preStart,int preEnd,int inStart,int inEnd){
	if(preStart>preEnd||inStart>inEnd) return;
	
	char root=preorder[preStart];
	int root_idx=inorder_idx[root-'A'];
	int numLefts=root_idx-inStart;
	// left subtree
	Postorder(preStart+1,preStart+numLefts,root_idx-numLefts,root_idx-1);
	// right subtree
	Postorder(preStart+numLefts+1,preEnd,root_idx+1,inEnd);
	// root
	postorder+=root;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	while(cin>>preorder){
		cin>>inorder;
		Size=inorder.size();
		memset(inorder_idx,0,sizeof(inorder_idx));
		for(int i=0;i<inorder.size();i++){
			inorder_idx[inorder[i]-'A']=i;
		}
		postorder="";
		Postorder(0,Size-1,0,Size-1);
		cout<<postorder<<endl;
	}

	return 0;
}
