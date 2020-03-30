#include <iostream>
#include <map>
#include <string>
using namespace std;

char firstCol[5];
int testcase,numRot;
int curIdx,nextIdx;
int info[6][5][4]={{{12,10,16,18},{11,13,17,15},{45,3,46,25},{44,6,47,22},{43,9,48,19}},\
									{{30,28,34,36},{29,31,35,33},{37,21,54,7},{38,24,53,4},{39,27,52,1}},\
									{{3,1,7,9},{2,4,8,6},{43,30,52,16},{40,33,49,13},{37,36,46,10}},\
									{{21,19,25,27},{20,22,26,24},{39,12,48,34},{42,15,51,31},{45,18,54,28}},\
									{{38,40,44,42},{39,37,43,45},{28,1,10,19},{29,2,11,20},{30,3,12,21}},\
									{{48,46,52,54},{47,49,53,51},{18,9,36,27},{17,8,35,26},{16,7,34,25}}\
								};
string cmd;

map<char,int> plane;
map<int,char> dice;

void Init(){
	plane['F']=0;plane['B']=1;
	plane['L']=2;plane['R']=3;
	plane['U']=4;plane['D']=5;
	
	for(int i=1;i<=54;i++){
		if(1<=i&&i<=9) dice[i]='g';
		else if(10<=i&&i<=18) dice[i]='r';
		else if(19<=i&&i<=27) dice[i]='b';
		else if(28<=i&&i<=36) dice[i]='o';
		else if(37<=i&&i<=45) dice[i]='w';
		else if(46<=i&&i<=54) dice[i]='y';
	}
}

void Rotate(char planeIdx){
	int idx=plane[planeIdx];
	for(int r=0;r<5;r++) firstCol[r]=dice[info[idx][r][0]];
	for(int r=0;r<5;r++){
		for(int c=1;c<=3;c++){
			curIdx=info[idx][r][c-1];
			nextIdx=info[idx][r][c];
			dice[curIdx]=dice[nextIdx];
		}
		curIdx=info[idx][r][3];
		dice[curIdx]=firstCol[r];
	}
}

void ClockWise(char planeIdx){
	Rotate(planeIdx);
}

void CounterClockWise(char planeIdx){
	for(int i=0;i<3;i++) Rotate(planeIdx);
}

void Print(){
	for(int i=37;i<=45;i++){
		cout<<dice[i];
		if(i%3==0) cout<<endl;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		Init();
		cin>>numRot;
		for(int i=0;i<numRot;i++){
			cin>>cmd;
			if(cmd[1]=='+') ClockWise(cmd[0]);
			else CounterClockWise(cmd[0]);
		}
		Print();
	}
	return 0;
}
