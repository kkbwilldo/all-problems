#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

char board[4][4];
string str;

bool TicTacToe(){
	for(int r=0;r<3;r++){
		if(board[r][0]==board[r][1]&&board[r][1]==board[r][2]&&board[r][0]!='.') return true;
	}
	for(int c=0;c<3;c++){
		if(board[0][c]==board[1][c]&&board[1][c]==board[2][c]&&board[0][c]!='.') return true;
	}
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!='.') return true;
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!='.') return true;
	return false;
}

void Play(int r,int c,char unit){
	
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>str;
	while(str!="end"){
		int X=0;
		int O=0;
		vector <pair<int,int> > pos;
		for(int i=0;i<str.size();i++){
			int r=i/3;
			int c=i%3;
			board[r][c]=str[i];
			if(str[i]=='X') X++;
			else if(str[i]=='O') O++;
			else pos.push_back(r,c);
		}
		if(!(0<=X-O&&X-O<=1)){
			cout<<"invalid"<<endl;
		}
		else{
			if(TicTacToe()) cout<<"valid"<<endl;
			else{
				
			}
		}

		cin>>str;
	}
	
	return 0;
}
