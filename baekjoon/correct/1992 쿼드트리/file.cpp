#include <iostream>
#include <string>
using namespace std;

const int MAX=80;

int mapSize;
string answer;
char board[MAX][MAX];

bool NotWhole(int StartR,int StartC,int size){	
	for(int r=StartR;r<StartR+size;r++){
		for(int c=StartC;c<StartC+size;c++){
			if(board[StartR][StartC]!=board[r][c]) return true;
		}
	}
	return false;
}

string Divide(int StartR,int StartC,int size){
	if(NotWhole(StartR,StartC,size)){
		string result="(";
		result+=Divide(StartR,StartC,size/2);
		result+=Divide(StartR,StartC+size/2,size/2);
		result+=Divide(StartR+size/2,StartC,size/2);
		result+=Divide(StartR+size/2,StartC+size/2,size/2);
		result+=")";
		return result;
	}
	else return string(1,board[StartR][StartC]);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>mapSize;
	for(int r=0;r<mapSize;r++){
		for(int c=0;c<mapSize;c++){
			cin>>board[r][c];
		}
	}
	answer=Divide(0,0,mapSize);
	cout<<answer<<endl;
	return 0;
}
