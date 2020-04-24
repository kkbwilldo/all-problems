#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int testcase;
int score,numRots;
int idx,dir;
int di[]={-1,1};
int visited[4];
int gears[4][8];

void CheckGears(int idx,int dir){
	memset(visited,0,sizeof(visited));
	visited[idx]=dir;
	queue <int> q;
	q.push(idx);
	while(!q.empty()){
		int gear=q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int nextGear=gear+di[i];
			if(nextGear<0||nextGear>=4) continue;
			if(visited[nextGear]!=0) continue;
			if(nextGear<gear){
				if(gears[nextGear][2]!=gears[gear][6]){
					visited[nextGear]=-visited[gear];
					q.push(nextGear);
				}
			}
			else{
				if(gears[gear][2]!=gears[nextGear][6]){
					visited[nextGear]=-visited[gear];
					q.push(nextGear);
				}
			}
		}
	}
}

void Rotate(){
	for(int i=0;i<4;i++){
		if(visited[i]==1){
			int temp=gears[i][7];
			for(int j=6;j>=0;j--) gears[i][j+1]=gears[i][j]; //ㅇㅕ기 틀림
			gears[i][0]=temp;
		}
		else if(visited[i]==-1){
			int temp=gears[i][0];
			for(int j=1;j<8;j++) gears[i][j-1]=gears[i][j]; //ㅇㅕ기 틀림
			gears[i][7]=temp;
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(gears,0,sizeof(gears));
		score=0;
		cin>>numRots;
		for(int i=0;i<4;i++){
			for(int j=0;j<8;j++){
				cin>>gears[i][j];
			}
		}
		for(int i=0;i<numRots;i++){
			cin>>idx>>dir;
			CheckGears(idx-1,dir);
			Rotate();
		}
		for(int i=0;i<4;i++) score+=pow(2,i)*gears[i][0];
		cout<<"#"<<test<<" "<<score<<endl;
	}
	return 0;
}
