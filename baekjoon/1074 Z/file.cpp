#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

ull exponent,ROW,COL;
ull idx,position,r,c;
bool hasDone;
bool visited[50][50];

void Z(){
	cout<<r<<","<<c<<endl;
	if(r==ROW&&c==COL){
		hasDone=true;
		return;
	}
	
	if(position==0||position==2) { 
		if(visited[r][c]) { hasDone=true;return;}
		idx++;position++;c++;
	} 
	else if(position==1){
		if(visited[r][c]) { hasDone=true;return;}
		visited[r][c]=true;
		idx++;position++;r++;c--;
	}
	else{
		if(visited[r][c]) { hasDone=true;return;}
		visited[r][c]=true;
		idx++;
		position=0;
		if(r==c){ r=0; c++; }
		else if(r<c){
			if(c/2==r) {r++; c=0;}
			else {r--;c++;}
		}
		else{
			if(r/2==c) { r=r/2+1;c++;}
			else{r--;c++;}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>exponent>>ROW>>COL;
	idx=position=r=c=0;
	hasDone=false;
	while(!hasDone) Z();
	cout<<idx<<endl;
	return 0;
}
