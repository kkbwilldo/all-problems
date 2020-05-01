#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 15;
const int INF = 987987987;

char map[MAX][MAX];
int ROW,COL;
int RR,RC,BR,BC;
int answer;
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
bool isRedIn,isBlueIn;
string str;

void GoStraight(int rr,int rc,int br,int bc,int moveCnt,int curDir){
	if(moveCnt>=10) return;
	if(moveCnt>=answer) return;
	isRedIn=isBlueIn=false;
	int nrr,nrc,nbr,nbc;
	nrr=rr+dr[curDir];
	nrc=rc+dc[curDir];
	while(1){
		if(map[nrr][nrc]=='#') break;
		if(map[nrr][nrc]=='O'){
			isRedIn=true;
			break;
		}
		nrr+=dr[curDir];
		nrc+=dc[curDir];
	}
	nrr-=dr[curDir];
	nrc-=dc[curDir];
	nbr=br+dr[curDir];
	nbc=bc+dc[curDir];
	while(1){
		if(map[nbr][nbc]=='#') break;
		if(map[nbr][nbc]=='O'){
			isBlueIn=true;
			break;
		}
		nbr+=dr[curDir];
		nbc+=dc[curDir];
	}
	nbr-=dr[curDir];
	nbc-=dc[curDir];
	if(isBlueIn) return;
	else{
		if(isRedIn){
			answer=min(answer,moveCnt+1);
			return;
		}
	}
	if(nrr==nbr&&nrc==nbc){
		int redDist=abs(nrr-rr)+abs(nrc-rc);
		int blueDist=abs(nbr-br)+abs(nbc-bc);
		if(redDist>blueDist){
			nrr-=dr[curDir];
			nrc-=dc[curDir];
		}
		else{
			nbr-=dr[curDir];
			nbc-=dc[curDir];
		}
	}
	for(int i=0;i<4;i++){
		if(i==curDir) continue;
		if(i==(curDir+2)%4) continue;
		GoStraight(nrr,nrc,nbr,nbc,moveCnt+1,i);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		cin>>str;
		for(int c=0;c<COL;c++){
			if(str[c]=='R'){
				RR=r;
				RC=c;
				map[r][c]='.';
			}
			else if(str[c]=='B'){
				BR=r;
				BC=c;
				map[r][c]='.';
			}
			else map[r][c]=str[c];
		}
	}
	answer=INF;
	for(int i=0;i<4;i++) GoStraight(RR,RC,BR,BC,0,i);
	if(answer==INF) answer=-1;
	cout<<answer<<endl;
	return 0;
}
