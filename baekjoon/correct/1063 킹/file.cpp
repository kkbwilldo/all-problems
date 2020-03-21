/*
map 자료구조를 이용하여 문자열을 숫자로 매핑한 후 이동시켰다.
킹의 다음 위치를 계산한 후 그 위치가 맵 밖이면 continue
킹의 다음 위치가 돌의 위치이면,
돌의 다음 위치를 계산한 후 그 위치가 맵 밖이면 continue
돌의 위치를 업데이트 한 후 킹의 위치를 마지막으로 업데이트 한다.
*/
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int moveCnt;
int kingR,kingC,rockR,rockC;
int nkingR,nkingC,nrockR,nrockC;
string kingPos,rockPos;
string Next;

int dr[]={0,0,1,-1,-1,-1,1,1};
int dc[]={1,-1,0,0,1,-1,1,-1};

map <string,int> Table;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	Table["R"]=0;Table["L"]=1;Table["B"]=2;Table["T"]=3;
	Table["RT"]=4;Table["LT"]=5;Table["RB"]=6;Table["LB"]=7;
	
	cin>>kingPos>>rockPos>>moveCnt;
	kingR=abs(kingPos[1]-'0'-8);
	kingC=kingPos[0]-'A';
	rockR=abs(rockPos[1]-'0'-8);
	rockC=rockPos[0]-'A';
	for(int i=0;i<moveCnt;i++){
		cin>>Next;
		nkingR=kingR+dr[Table[Next]];
		nkingC=kingC+dc[Table[Next]];
		if(nkingR<0||nkingR>=8||nkingC<0||nkingC>=8) continue;
		if(nkingR==rockR&&nkingC==rockC){
			nrockR=rockR+dr[Table[Next]];
			nrockC=rockC+dc[Table[Next]];
			if(nrockR<0||nrockR>=8||nrockC<0||nrockC>=8) continue;
			rockR=nrockR;
			rockC=nrockC;
		}
		kingR=nkingR;
		kingC=nkingC;
	}
	cout<<char(kingC+'A')<<abs(kingR-8)<<endl;
	cout<<char(rockC+'A')<<abs(rockR-8)<<endl;
	return 0;
}


