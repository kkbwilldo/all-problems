#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
using namespace std;

int rot,sum;
int gearNum,dir;
int visited[5];
string gears[5];

void Which(int gear,int d){
	memset(visited,0,sizeof(visited));
	visited[gear]=d;
	queue <pair<int,int> > q;
	q.push(make_pair(gear,d));
	while(!q.empty()){
		int gearNum=q.front().first;
		int dir=q.front().second;
		q.pop();
		for(int i=1;i<=2;i++){
			int next=gearNum;
			if(i==1) next-=1;
			else next+=1;
			if(next<1||next>4) continue;
			if(visited[next]) continue;
			if(i==1){
				if(gears[next][2]!=gears[gearNum][6]){
					visited[next]=dir*-1;
					q.push(make_pair(next,dir*-1));
				}
			}
			else{
				if(gears[next][6]!=gears[gearNum][2]){
					visited[next]=dir*-1;
					q.push(make_pair(next,dir*-1));
				}
			}
		}
	}
}

void Rotate(){
	for(int i=1;i<=4;i++){
		if(visited[i]==1){
			string subStr = gears[i].substr(0,7);
			subStr = gears[i][7]+subStr;
			gears[i] = subStr;
		}
		else if(visited[i]==-1){
			string subStr = gears[i].substr(1,8);
			subStr = subStr+gears[i][0];
			gears[i] = subStr;
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=1;i<=4;i++) cin>>gears[i];
	cin>>rot;
	for(int i=0;i<rot;i++){
		cin>>gearNum>>dir;
		Which(gearNum,dir);
		Rotate();
	}
	
	sum+=(gears[1][0]-'0')*1;
	sum+=(gears[2][0]-'0')*2;
	sum+=(gears[3][0]-'0')*4;
	sum+=(gears[4][0]-'0')*8;
	cout<<sum<<endl;
	return 0;
}
