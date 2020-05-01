#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;

int numDragons;
int r,c,dir,genCnt;
int answer;
int dr[]={0,-1,0,1};
int dc[]={1,0,-1,0};
int dx[]={1,1,0};
int dy[]={0,1,1};
bool visited[MAX][MAX];

void MakeDirSeq(vector <int> &dirs,int genCnt){
	if(genCnt<=0) return;
	int size=dirs.size();
	for(int i=size-1;i>=0;i--){
		int dir=dirs[i];
		dirs.push_back((dir+1)%4);
	}
	MakeDirSeq(dirs,genCnt-1);
}

void MarkVertice(vector <int> &dirs,int r,int c){
	visited[r][c]=true;
	int nr=r;
	int nc=c;
	for(int i=0;i<dirs.size();i++){
		int idx=dirs[i];
		nr+=dr[idx];
		nc+=dc[idx];
		visited[nr][nc]=true;
	}
}

void GetNumSqr(){
	for(int r=0;r<MAX;r++){
		for(int c=0;c<MAX;c++){
			if(visited[r][c]){
				int cnt=1;
				for(int i=0;i<3;i++){
					int nr=r+dx[i];
					int nc=c+dy[i];
					if(nr<0||nr>=MAX||nc<0||nc>=MAX) break;
					if(visited[nr][nc]) cnt++;
				}
				if(cnt==4) answer++;
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numDragons;
	for(int i=0;i<numDragons;i++){
		cin>>c>>r>>dir>>genCnt;
		vector <int> dragon;
		dragon.push_back(dir);
		MakeDirSeq(dragon,genCnt);
		MarkVertice(dragon,r,c);
	}
	GetNumSqr();
	cout<<answer<<endl;
	return 0;
}
