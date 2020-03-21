#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 100;

vector <int> heavy[MAX];
vector <int> light[MAX];

int numBeads,times,mid;
int a,b,hcnt,lcnt,cant;
bool hvisited[MAX];
bool lvisited[MAX];


void hbfs(int s){
	hvisited[s] = true;
	queue <int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<heavy[cur].size();i++){
			int next = heavy[cur][i];
			if(!hvisited[next]){
				hvisited[next]=true;
				hcnt++;
				q.push(next);
			}
		}
	}
}


void lbfs(int s){
	lvisited[s]=true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0;i<light[cur].size();i++){
			int next = light[cur][i];
			if(!lvisited[next]){
				lvisited[next]=true;
				lcnt++;
				q.push(next);
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>numBeads>>times;
	mid=numBeads/2+1;
	

	for(int i=0;i<times;i++){
		cin>>a>>b;
		heavy[a].push_back(b);
		light[b].push_back(a);
	}
	//	중복 제거
	
	for(int i=1;i<=numBeads;i++){
		hcnt=lcnt=0;
		memset(hvisited,0,sizeof(hvisited));
		memset(lvisited,0,sizeof(lvisited));
		hbfs(i);
		lbfs(i);
		if(hcnt>=mid || lcnt>= mid) cant++;
	}
	
	cout<<cant<<endl;
	return 0;
}
