#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
using namespace std;

const int MAX = 1010;

int numGear,rot,sum;
int gearNum,dir;
int visited[MAX];
string gears[MAX];

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
			if(next<1||next>numGear) continue;
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
	for(int i=1;i<=numGear;i++){
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
	
	cin>>numGear;
	for(int i=1;i<=numGear;i++) cin>>gears[i];
	cin>>rot;
	for(int i=0;i<rot;i++){
		cin>>gearNum>>dir;
		Which(gearNum,dir);
		Rotate();
	}
	for(int i=1;i<=numGear;i++) sum+=gears[i][0]-'0';
	cout<<sum<<endl;
	return 0;
}
