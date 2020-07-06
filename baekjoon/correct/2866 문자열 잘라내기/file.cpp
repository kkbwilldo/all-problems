#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const int MAX=1010;

int ROW,COL;
char table[MAX][MAX];

bool isDuplicates(int StartR){
	unordered_set <string> check;
	for(int c=0;c<COL;c++){
		string str="";
		for(int r=StartR;r<ROW;r++){
			str+=string(1,table[r][c]);
		}
		if(check.find(str)!=check.end()){
			return true;
		}
		check.insert(str);
	}
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	for(int r=0;r<ROW;r++){
		for(int c=0;c<COL;c++){
			cin>>table[r][c];
		}
	}
	
	int Start=0;
	int End=ROW-1;
	while(Start<=End){
		int Mid=(Start+End)/2;
		if(isDuplicates(Mid)) End=Mid-1; // 중복 있을 때 이동
		else Start=Mid+1; // 중복 없을 때 이동
	}

	cout<<End<<endl;
	return 0;
}
