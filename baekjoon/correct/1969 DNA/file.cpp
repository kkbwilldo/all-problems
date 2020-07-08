#include <iostream>
#include <string>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

const int MAX=1010;
const int INF=987987987;

int numStrs,size,minDist;
string str,answer;
vector <string> strs;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	answer="";
	cin>>numStrs>>size;
	for(int i=0;i<numStrs;i++){
		cin>>str;
		strs.push_back(str);
	}
	
	for(int c=0;c<size;c++){
		map <char,int> check;
		for(int r=0;r<numStrs;r++){
			char letter=strs[r][c];
			if(check.find(letter)==check.end()) check[letter]=1;
			else check[letter]++;
		}
		int maxVal=0;
		char letter;
		for(auto iter=check.begin();iter!=check.end();iter++){
			if(maxVal<iter->second){
				letter=iter->first;
				maxVal=iter->second;
			}
		}
		answer+=string(1,letter);
	}
	
	for(int i=0;i<numStrs;i++){
		for(int j=0;j<size;j++){
			if(answer[j]!=strs[i][j]) minDist++;
		}
	}

	cout<<answer<<endl<<minDist<<endl;
	return 0;
}
