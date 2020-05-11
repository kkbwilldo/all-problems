#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	string answer = "";
	map <char,int> table;
	for(int i=0;i<sentence.size();i++){
		char letter=sentence[i];
		if('A'<=letter&&letter<='Z') answer+=string(1,letter);
		else{
			if(table.find(letter)==table.end()) table[letter]=1;
			else table[letter]++;
		}
	}
	for(auto iter=table.begin();iter!=table.end();iter++){
		if(iter->second==1) return"invalid";
	}
	return answer;
}

int main ()
{
	vector <string> sentences={"HaEaLaLaObWORLDb","SpIpGpOpNpGJqOqA",
"AxAxAxAoBoBoB"};
	for(int i=0;i<sentences.size();i++){
		string sentence=sentences[i];
		string answer=solution(sentence);
		cout<<answer<<endl;
	}
	return 0;
}
