#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#define endl '\n'
using namespace std;

char how[10001];
int testcase;
int Start,End;
int dist[10001];
int from[10001];
bool visited[10001];

void Print(int Start,int End){
	if(Start==End) return;
	Print(Start,from[End]);
	cout<<how[End];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>Start>>End;
		memset(visited,false,sizeof(visited));
		memset(dist,0,sizeof(dist));
		memset(how,0,sizeof(how));
		memset(from,0,sizeof(from));
		visited[Start]=true;
		dist[Start]=0;
		from[Start]=-1;
		queue <int> q;
		q.push(Start);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			
			// Double
			int next=(now*2)%10000;
			if(!visited[next]){
				q.push(next);
				visited[next]=true;
				dist[next]=dist[now]+1;
				from[next]=now;
				how[next]='D';
			}
			
			// Subtract
			next=now-1;
            if(next == -1) next = 9999;
            if(!visited[next]){
				q.push(next);
				visited[next] = true;
				dist[next] = dist[now]+1;
				from[next] = now;
				how[next] = 'S';
			}
			
			// Left
			next = (now%1000)*10 + now/1000;
            if(!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[now]+1;
				from[next] = now;
				how[next] = 'L';
			}
			
			//Right
			next = (now/10) + (now%10)*1000;
            if(!visited[next]){
				q.push(next);
				visited[next] = true;
				dist[next] = dist[now]+1;
				from[next] = now;
				how[next] = 'R';
			}
		}
		Print(Start,End);
		cout<<endl;
	}
    return 0;
}
