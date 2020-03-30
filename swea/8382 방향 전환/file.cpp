#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

const int INF=987987987;

struct item{
	int r,c,dist;
	string dir;
	item(int _r,int _c,int _dist,string _dir):r(_r),c(_c),dist(_dist),dir(_dir){}
};

int testcase;
int startR,startC,endR,endC;
int minVal;
int lowR,lowC,upperR,upperC;

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

void bfs(string direction){
	set <pair<int,int> > visited;
	queue <item> q;
	visited.insert(make_pair(startR,startC));
	q.push(item(startR,startC,0,direction));
	while(!q.empty()){
		int r=q.front().r;
		int c=q.front().c;
		int dist=q.front().dist;
		string dir=q.front().dir;
		q.pop();
		if(r==endR&&c==endC){
			minVal=min(minVal,dist);
			return;
		}
		if(dist>=minVal) continue;
		for(int i=0;i<4;i++){
			if(dir=="horz"&&(i==0||i==1)) continue;
			if(dir=="vert"&&(i==2||i==3)) continue;
			int nr=r+dr[i];
			int nc=c+dc[i];
			string next="vert";
			if(dir=="vert") next="horz";
			if(nr<lowR||nr>upperR||nc<lowC||nc>upperC) continue;
			if(visited.find(make_pair(nr,nc))!=visited.end()) continue;
			visited.insert(make_pair(nr,nc));
			q.push(item(nr,nc,dist+1,next));
		}
	}
}

void setting(){
	if(startR<endR){
		lowR=startR;
		upperR=endR;
	}
	else if(startR>endR){
		lowR=endR;
		upperR=startR;
	}
	else{
		lowR=startR-1;
		upperR=startR+1;
	}
	if(startC<endC){
		lowC=startC;
		upperC=endC;
	}
	else if(startC>endC){
		lowC=endC;
		upperC=startC;
	}
	else{
		lowC=startC-1;
		upperC=startC+1;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>startR>>startC>>endR>>endC;
		if(startR==endR&&startC==endC){
			cout<<"#"<<test<<" "<<0<<endl;
			continue;
		}
		minVal=INF;
		setting();
		bfs("vert");
		bfs("horz");
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	
	return 0;
}
