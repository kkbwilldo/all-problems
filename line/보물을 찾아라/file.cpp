#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

const int MAX = 30;

int ROW,COL;
int StartR,StartC;
int hitR,hitC;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int dists[MAX][MAX];
int numPaths[MAX][MAX];
bool visited[MAX][MAX];

void FindShortCut(){
  visited[StartR][StartC]=true;
  queue <tuple<int,int,int> > q;
  q.push(make_tuple(StartR,StartC,0));
  while(!q.empty()){
    int r,c,dist;
    tie(r,c,dist)=q.front();
    q.pop();
    dists[r][c]=dist;
    for(int i=0;i<4;i++){
      int nr=r+dr[i];
      int nc=c+dc[i];
      int ndist=dist+1;
      if(nr<0||nr>=ROW||nc<0||nc>=COL) continue;
      if(visited[nr][nc]) continue;
      visited[nr][nc]=true;
      q.push(make_tuple(nr,nc,ndist));
    }
  }
}

void FindPaths(){
  for(int c=0;c<COL;c++) numPaths[0][c]=1;
  for(int r=0;r<ROW;r++) numPaths[r][0]=1;
  for(int r=0;r<ROW;r++){
    for(int c=0;c<COL;c++){
      if(numPaths[r][c]!=0) continue;
      numPaths[r][c]=numPaths[r-1][c]+numPaths[r][c-1];
    }
  }
}

void Print(){
  for(int r=0;r<ROW;r++){
    for(int c=0;c<COL;c++){
      cout<<dists[r][c]<<" ";
    }cout<<endl;
  }cout<<endl;
  
  for(int r=0;r<ROW;r++){
    for(int c=0;c<COL;c++){
      cout<<numPaths[r][c]<<" ";
    }cout<<endl;
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  
  cin>>ROW>>COL;
  cin>>hitR>>hitC;
  FindShortCut();
  FindPaths();
  if((hitR==0&&hitC==0)||(hitR>=ROW||hitC>=COL)) cout<<"fail"<<endl;
  else cout<<dists[hitR][hitC]<<endl<<numPaths[hitR][hitC]<<endl;
  //Print();
  return 0;
}
