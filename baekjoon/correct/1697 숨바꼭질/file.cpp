#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

const int MAX=100001;

int Subin,Dongsang,answer;
int board[MAX+10];
bool visited[MAX+10];

int GetNext(int cur,int type){
	if(type==0) return cur-1;
	else if(type==1) return cur+1;
	else return cur*2;
}

void bfs(){
	visited[Subin]=true;
	queue <int> q;
	q.push(Subin);
	while(!q.empty()){
		bool flag=false;
		int size=q.size();
		int minVal=min(size,3);
		for(int i=0;i<size;i++){
			int cur=q.front();
			q.pop();
			if(cur==Dongsang) return;
			for(int j=0;j<3;j++){
				int Next=GetNext(cur,j);
				if(Next<0||Next>=MAX) continue;
				if(visited[Next]) continue;
				visited[Next]=true;
				q.push(Next);
				flag=true;
			}
		}
		if(flag) answer++;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>Subin>>Dongsang;
	bfs();
	cout<<answer<<endl;
	return 0;
}
