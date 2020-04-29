#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX=20;
const int INF=987987987;

int testcase;
int ROW,COL,numSerial,answer;
int board[MAX][MAX];
int copy_board[MAX][MAX];
bool Select[MAX];

bool Check(int map[][MAX]){
	for(int c=0;c<COL;c++){
		int A_Cnt=0;
		int B_Cnt=0;
		bool pass=false;
		for(int r=0;r<ROW;r++){
			if(map[r][c]==0){ // A
				A_Cnt++;
				B_Cnt=0;
			}
			else{ // B
				A_Cnt=0;
				B_Cnt++;
			}
			if(A_Cnt==numSerial||B_Cnt==numSerial){
				pass=true;
				break;
			}
		}
		if(pass==false) return false;
	}
	return true;
}

void Dope(int r,int indicator,string type){
	if(type=="inject"){
		for(int c=0;c<COL;c++) copy_board[r][c]=indicator;
	}
	else if(type=="rollBack"){
		for(int c=0;c<COL;c++) copy_board[r][c]=board[r][c];
	}
}

void AllCases(int row,int numPicks){
	if(numPicks>numSerial||numPicks>=answer) return;
	if(Check(copy_board)==true){
		answer=min(answer,numPicks);
		return;
	}
	for(int r=row;r<ROW;r++){ // r=row로 조합 구현 
		if(Select[r]==true) continue;
		Select[r]=true;
		for(int i=0;i<2;i++){
			Dope(r,i,"inject");
			AllCases(r,numPicks+1);
			Dope(r,i,"rollBack");
		}
		Select[r]=false; // 뽑은거 취소 
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		answer=INF;
		memset(board,0,sizeof(board));
		memset(copy_board,0,sizeof(copy_board));
		memset(Select,0,sizeof(Select));
		cin>>ROW>>COL>>numSerial;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>board[r][c];
				copy_board[r][c]=board[r][c];
			}
		}
		if(Check(board)){
			cout<<"#"<<test<<" "<<0<<endl;
			continue;
		}
		AllCases(0,0);
		cout<<"#"<<test<<" "<<answer<<endl;
	}
	
	return 0;
}
