#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 110;

int answer;
int numLadders,numSnakes;
int curPos,nextPos;
int jumps[MAX];
bool visited[MAX];

int Move(){
	int Start=1;
	int End=100;
	int cnt=0;
	visited[Start]=true;
	queue <pair<int,int> > q;
	q.push(make_pair(Start,cnt));
	while(!q.empty()){
		curPos=q.front().first;
		cnt=q.front().second;
		q.pop();
		if(curPos==End) return cnt;
		if(jumps[curPos]) curPos=jumps[curPos];
		for(int i=1;i<=6;i++){
			nextPos=curPos+i;
			if(nextPos>End) break;
			if(visited[nextPos]) continue;
			visited[nextPos]=true;
			q.push(make_pair(nextPos,cnt+1));
		}
	}
	return -1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numLadders>>numSnakes;
	for(int i=0;i<numLadders;i++){
		cin>>curPos>>nextPos;
		jumps[curPos]=nextPos;
	}
	for(int i=0;i<numSnakes;i++){
		cin>>curPos>>nextPos;
		jumps[curPos]=nextPos;
	}
	answer=Move();
	cout<<answer<<endl;
	return 0;
}
