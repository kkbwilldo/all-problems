#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define endl '\n'
using namespace std;

const int MAX=55;

int size,answer;
int board[MAX][MAX],temp[MAX][MAX];

vector <int> Sang,Sun;

void SetUpperLeft(int StartR,int StartC){
	Sang.clear();
	for(int r=StartR;r>=0;r--){
		for(int c=StartC;c>=0;c--){
			if(c==StartC) temp[r][c]=board[r][c];
			else temp[r][c]=board[r][c]+temp[r][c+1];
		}
	}
	for(int r=StartR-1;r>=0;r--){
		for(int c=StartC;c>=0;c--){
			temp[r][c]+=temp[r+1][c];
		}
	}
	for(int r=StartR;r>=0;r--){
		for(int c=StartC;c>=0;c--){
			Sang.push_back(temp[r][c]);
		}
	}
	sort(Sang.begin(),Sang.end());
}

void SetUpperRight(int StartR,int StartC){
	Sun.clear();
	for(int r=StartR;r>=0;r--){
		for(int c=StartC;c<size;c++){
			if(c==StartC) temp[r][c]=board[r][c];
			else temp[r][c]=board[r][c]+temp[r][c-1];
		}
	}
	for(int r=StartR-1;r>=0;r--){
		for(int c=StartC;c<size;c++){
			temp[r][c]+=temp[r+1][c];
		}
	}
	for(int r=StartR;r>=0;r--){
		for(int c=StartC;c<size;c++){
			Sun.push_back(temp[r][c]);
		}
	}
	sort(Sun.begin(),Sun.end());
}

void SetLowerLeft(int StartR,int StartC){
	Sang.clear();
	for(int r=StartR;r<size;r++){
		for(int c=StartC;c>=0;c--){
			if(c==StartC) temp[r][c]=board[r][c];
			else temp[r][c]=board[r][c]+temp[r][c+1];
		}
	}
	for(int r=StartR+1;r<size;r++){
		for(int c=StartC;c>=0;c--){
			temp[r][c]+=temp[r-1][c];
		}
	}
	for(int r=StartR;r<size;r++){
		for(int c=StartC;c>=0;c--){
			Sang.push_back(temp[r][c]);
		}
	}
	sort(Sang.begin(),Sang.end());
}

void SetLowerRight(int StartR,int StartC){
	Sun.clear();
	for(int r=StartR;r<size;r++){
		for(int c=StartC;c<size;c++){
			if(c==StartC) temp[r][c]=board[r][c];
			else temp[r][c]=board[r][c]+temp[r][c-1];
		}
	}
	for(int r=StartR+1;r<size;r++){
		for(int c=StartC;c<size;c++){
			temp[r][c]+=temp[r-1][c];
		}
	}
	for(int r=StartR;r<size;r++){
		for(int c=StartC;c<size;c++){
			Sun.push_back(temp[r][c]);
		}
	}
	sort(Sun.begin(),Sun.end());
}

void AllCases(){
	answer=0;
	for(int r=0;r<size-1;r++){
		for(int c=0;c<size-1;c++){
			SetUpperLeft(r,c);
			SetLowerRight(r+1,c+1);
			for(int i=0;i<Sang.size();i++){
				for(int j=0;j<Sun.size();j++){
					if(Sang[i]==Sun[j]) answer++;
					else if(Sang[i]<Sun[j]) break;
				}
			}
		}
	}
	for(int r=size-1;r>=1;r--){
		for(int c=0;c<size-1;c++){
			SetLowerLeft(r,c);
			SetUpperRight(r-1,c+1);
			for(int i=0;i<Sang.size();i++){
				for(int j=0;j<Sun.size();j++){
					if(Sang[i]==Sun[j]) answer++;
					else if(Sang[i]<Sun[j]) break;
				}
			}
		}
	}
}

void Print(int StartR,int StartC,int EndR,int EndC){
	for(int r=min(StartR,EndR);r<=max(StartR,EndR);r++){
		for(int c=min(StartC,EndC);c<=max(StartC,EndC);c++){
			cout<<temp[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>board[r][c];
		}
	}
	
	AllCases();

	cout<<answer<<endl;
	return 0;
}
