#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
	string answer = "";
	char Board[m][n];
	map <char,vector<pair<int,int> > > table;
	for(int r=0;r<m;r++){
		for(int c=0;c<n;c++){
			Board[r][c]=board[r][c];
			if(Board[r][c]!='*')
				table[Board[r][c]].push_back(make_pair(r,c));
		}
	}
	for(auto iter=table.begin();iter!=table.end();iter++){
		int firstR,firstC,secondR,secondC;
		firstR=iter->second[0].first;
		firstC=iter->second[0].second;
		secondR=iter->second[1].first;
		secondC=iter->second[1].second;
		
	}
	return answer;
}

int main ()
{
	int m,n;
	m=3;
	n=3;
	vector <string> board={"DBA", "C*A", "CDB"};
	string ans=solution(m,n,board);
	cout<<ans<<endl;
	return 0;
}
