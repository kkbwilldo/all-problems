#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

const int MAX=110;

int testcase;
int numConvs,numBeers;
int StartR,StartC,EndR,EndC;
int r,c;
string answer;
bool visited[MAX];

vector <pair<int,int> > pos;

int GetBeers(int StartR,int StartC,int EndR,int EndC){
	int dist=abs(StartR-EndR)+abs(StartC-EndC);
	int val=dist/50;
	if(dist%50!=0) val+=1;
	return val;
}

void Init(){
	memset(visited,0,sizeof(visited));
	pos.clear();
	numBeers=20;
	answer="sad";
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		Init();
		
		cin>>numConvs;
		for(int i=0;i<numConvs+2;i++){
			cin>>r>>c;
			pos.push_back(make_pair(r,c));
			if(i==0){
				StartR=r;
				StartC=c;
			}
			else if(i==numConvs+2-1){
				EndR=r;
				EndC=c;
			}
		}
		
		visited[0]=true;
		queue <tuple<int,int>> q; 
		q.push(make_tuple(0,numBeers));
		while(!q.empty()){
			int curNode,curBeers;
			tie(curNode,curBeers)=q.front();
			q.pop();
			r=pos[curNode].first;
			c=pos[curNode].second;
			if(r==EndR&&c==EndC){
				answer="happy";
				break;
			}
			for(int i=1;i<numConvs+2;i++){
				int Next=i;
				int nr=pos[Next].first;
				int nc=pos[Next].second;
				int numBeers=GetBeers(r,c,nr,nc);
				if(curNode==Next) continue;
				if(visited[Next]) continue;
				if(numBeers>curBeers) continue;
				visited[Next]=true;
				q.push(make_tuple(Next,20));
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}
