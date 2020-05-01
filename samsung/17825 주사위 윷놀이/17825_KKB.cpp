#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

int maxVal;
int pos[4];
int dice[10];
int pick[10];
bool visited[33];
int Table[33][6]={
{0,1,2,3,4,5},			 //0
{2,2,3,4,5,6},			 //1
{4,3,4,5,6,7},			 //2
{6,4,5,6,7,8},			 //3
{8,5,6,7,8,9},			 //4
{10,20,21,22,28,29}, //5
{12,7,8,9,10,11},		 //6
{14,8,9,10,11,12},	 //7
{16,9,10,11,12,13},	 //8
{18,10,11,12,13,14}, //9
{20,23,24,28,29,30}, //10
{22,12,13,14,15,16},//11
{24,13,14,15,16,17},//12
{26,14,15,16,17,18},//13
{28,15,16,17,18,19},//14
{30,25,26,27,28,29},//15
{32,17,18,19,31,32},//16
{34,18,19,31,32,32},//17
{36,19,31,32,32,32},//18
{38,31,32,32,32,32},//19
{13,21,22,28,29,30},//20
{16,22,28,29,30,31},//21
{19,28,29,30,31,32},//22
{22,24,28,29,30,31},//23
{24,28,29,30,31,32},//24
{28,26,27,28,29,30},//25
{27,27,28,29,30,31},//26
{26,28,29,30,31,32},//27
{25,29,30,31,32,32},//28
{30,30,31,32,32,32},//29
{35,31,32,32,32,32},//30
{40,32,32,32,32,32},//31
{0,32,32,32,32,32}//32
};

void CheckScore(){
	memset(visited,0,sizeof(visited));
	memset(pos,0,sizeof(pos));
	int score=0;
	for(int depth=0;depth<10;depth++){
		int curPlayer=pick[depth];
		int curPos=pos[curPlayer];
		int diceRoll=dice[depth];
		int nextPos=Table[curPos][diceRoll];
		if(1<=nextPos&&nextPos<=31&&visited[nextPos]) return;
		visited[nextPos]=true;
		visited[curPos]=false;
		pos[curPlayer]=nextPos;
		score+=Table[nextPos][0];
	}
	maxVal=max(maxVal,score);
}

void AllCases(int depth){
	if(depth==10){
		CheckScore();
		return;
	}
	for(int playerIdx=0;playerIdx<4;playerIdx++){
		pick[depth]=playerIdx;
		AllCases(depth+1);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<10;i++) cin>>dice[i];
	AllCases(0);
	cout<<maxVal<<endl;
	return 0;
}
