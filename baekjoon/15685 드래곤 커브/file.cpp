#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;

int numDragons;
int StartR,StartC,dir,generation;
int dx[]={1,1,0};
int dy[]={0,1,1};
int dr[]={0,-1,0,1};
int dc[]={1,0,-1,0};
bool visited[MAX][MAX];

vector <int> directions;

void AddDirections(){
	int size=directions.size();
	for(int i=size-1;i>=0;i--){
		int curDir=directions[i];
		int nextDir=(curDir+1)%4;
		directions.push_back(nextDir);
	}
}

void GenerateDirections(){
	directions.clear();
	directions.push_back(dir);
	for(int i=0;i<=generation;i++) AddDirections();
	cout<<StartR<<","<<StartC<<endl;
	for(int i=0;i<directions.size();i++) cout<<directions[i]<<" ";
	cout<<endl;
}

void MarkVertice(){
	visited[StartR][StartC]=true;
	int r=StartR;
	int c=StartC;
	for(int i=0;i<directions.size();i++){
		int curDir=directions[i];
		r+=dr[curDir];
		c+=dc[curDir];
		visited[r][c]=true;		
	}
}

int NumSquares(){
	int numSqrs=0;
	for(int r=0;r<MAX;r++){
		for(int c=0;c<MAX;c++){
			if(visited[r][c]){
				int cnt=0;
				for(int i=0;i<3;i++){
					int nr=r+dx[i];
					int nc=c+dy[i];
					if(nr<0||nr>=MAX||nc<0||nc>=MAX) break;
					if(!visited[nr][nc]) break;
					cnt++;
				}
				if(cnt==3) numSqrs++;
			}
		}
	}
	return numSqrs;
}

void Print(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<visited[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numDragons;
	for(int i=0;i<numDragons;i++){
		cin>>StartR>>StartC>>dir>>generation;
		GenerateDirections();
		MarkVertice();
	}
	Print();
	int ans=NumSquares();
	cout<<ans<<endl;
	
	return 0;
}
