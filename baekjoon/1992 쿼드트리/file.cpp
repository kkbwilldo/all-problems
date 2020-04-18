#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int MAX = 70;

char map[MAX][MAX];
string str;
string answer;

string Divide(int r,int c,int size,int type){
	char Reference[1];
	int StartR=r,StartC=c;
	if(type==1) StartC=c-size+1;
	else if(type==2) StartR=r-size+1;
	else if(type==3){
		StartR=r-size+1;
		StartC=c-size+1;
	}
	Reference[0] = map[StartR][StartC];
	if(size<=1) return string(Reference);
	bool isWhole=true;
	for(int x=StartR;x<StartR+size;x++){
		for(int y=StartC;y<StartC+size;y++){
			if(Reference[0]!=map[x][y]){
				isWhole=false;
				break;
			}
		}
		if(!isWhole) break;
	}
	if(isWhole) return string(Reference);
	string first,second,third,forth;
	first=Divide(StartR,StartC,size/2,0);
	second=Divide(StartR,StartC+size-1,size/2,1);
	third=Divide(StartR+size-1,StartC,size/2,2);
	forth=Divide(StartR+size-1,StartC+size-1,size/2,3);
	return "("+first+second+third+forth+")";
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int size;
	cin>>size;
	for(int r=0;r<size;r++){
		cin>>str;
		for(int c=0;c<size;c++){
			map[r][c]=str[c];
		}
	}
	answer=Divide(0,0,size,0);
	cout<<answer<<endl;
	return 0;
}
