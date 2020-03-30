#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10010;

struct node{
    int x,y;
    int nodeNum;
    node* Left;
    node* Right;
    node():x(-1),y(-1),nodeNum(-1),Left(NULL),Right(NULL){}
    node(int _x,int _y,int _nodeNum):x(_x),y(_y),nodeNum(_nodeNum),Left(NULL),Right(NULL){};
};

node nodes[MAX];
vector<vector<int>> answer(2);

bool cmp(const node& a,const node& b){
    if(a.y>b.y) return true;
    else if(a.y==b.y){
        if(a.x<b.x) return true;
    }
    return false;
}

void insert(node* root,node* Node){
    if(root==NULL){
        Node->Left=Node->Right=NULL;
        root=Node;
    }
    else{
        if(root->x>Node->x) insert(root->Left,Node);
        else insert(root->Right,Node);
    }
}

void preorder(node* Node){
    answer[0].push_back(Node->nodeNum);
    if(Node->Left) preorder(Node->Left);
    if(Node->Right) preorder(Node->Right);
}

void postorder(node* Node){
    if(Node->Left) postorder(Node->Left);
    if(Node->Right) postorder(Node->Right);
    answer[1].push_back(Node->nodeNum);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i=0;i<nodeinfo.size();i++){
        int x=nodeinfo[i][0];
        int y=nodeinfo[i][1];
        nodes[i]=node(x,y,i+1);
    }
    sort(nodes,nodes+nodeinfo.size(),cmp);
    
    node* root=new node();
    for(int i=0;i<nodeinfo.size();i++){
        int x=nodes[i].x;
        int y=nodes[i].y;
        int idx=nodes[i].nodeNum;
        node Node = node(x,y,idx);
        insert(root,&Node);
    }
    preorder(root);
    postorder(root);
    return answer;
}
