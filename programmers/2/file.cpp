#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

char order[3];
char ops[]={'*','+','-'};
long long maxVal;
bool visited[3];
string first,second,third;
vector <string> elements;
stack <string> s;

vector <string> MakePostfix(){ // 각 우선순위에 맞게 바뀐 후위표기식 벡터 
	// ex) 3*2+1 -> "3" "2" "*" "1" "+" // 문자열 원소로 만들어진 벡터를 반환
	vector <string> answer;
	for(int i=0;i<elements.size();i++){
		if(i%2==0) answer.push_back(elements[i]); // 숫자인 경우
		else{ // 연산자인 경우
			string letter=elements[i];
			if(letter==first){ // 제일 높은 우선순위
				while(!s.empty()&&(s.top()==first)){
					answer.push_back(s.top());
					s.pop();
				}
				s.push(letter);
			}
			else if(letter==second){ // 두번째 우선순위
				while(!s.empty()&&(s.top()!=third)){
					answer.push_back(s.top());
					s.pop();
				}
				s.push(letter);
			}
			else if(letter==third){ // 제일 낮은 우선순위
				while(!s.empty()){
					answer.push_back(s.top());
					s.pop();
				}
				s.push(letter);
			}
		}
	}
	while(!s.empty()){
		answer.push_back(s.top());
		s.pop();
	}
	return answer; // 문자열 벡터를 반환
}

long long GetResult(vector <string> expression){ // 후위표기 벡터를 계산
	long long answer=0;
	stack <long long> s;
	for(int i=0;i<expression.size();i++){
		string letter=expression[i];
		if(letter=="*"||letter=="+"||letter=="-"){

			long long two=s.top();
			s.pop();
			long long one=s.top();
			s.pop();
			
			if(letter=="*"){
				long long result=one*two;
				s.push(result);
			}
			else if(letter=="+"){
				long long result=one+two;
				s.push(result);
			}
			else if(letter=="-"){
				long long result=one-two;
				s.push(result);
			}
		}
		else s.push(stoi(letter));
	}
	return s.top();
}

void AllCases(int depth){ // 6개 경우의 수
	if(depth==3){ // 우선순위가 모두 정해짐
		first=string(1,order[0]); // 첫번째 우선순위
		second=string(1,order[1]);// 두번째 우선순위
		third=string(1,order[2]);// 세번째 우선순위
		vector <string> expression=MakePostfix(); 
		long long result=GetResult(expression);
		maxVal=max(maxVal,abs(result));
		return;
	}
	for(int i=0;i<3;i++){
		if(visited[i]) continue;
		visited[i]=true;
		order[depth]=ops[i];
		AllCases(depth+1);
		visited[i]=false;
	}
}

long long solution(string expression) {
	long long answer = 0;
	int idx=0;
	// 문자열을 숫자와 연산자 문자열로 구분하여 elements 벡터에 순차적으로 푸쉬
	
	for(int i=0;i<expression.size();i++){
		char letter=expression[i];
		if('0'<=letter&&letter<='9') continue;
		else{
			elements.push_back(expression.substr(idx,i-idx));
			idx=i+1;
			elements.push_back(string(1,letter));
		}
	}
	elements.push_back(expression.substr(idx,expression.size()-idx));
	
	maxVal=0;
	AllCases(0);
	answer=maxVal;
	return answer;
}


