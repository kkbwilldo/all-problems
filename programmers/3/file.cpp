#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	const int INF=987987987;
	int minVal=INF;
	int Start=1,End=1;
	vector<int> answer;
	map <string,int> table,check;
	for(int i=0;i<gems.size();i++) table[gems[i]]=1;
	int size=table.size();
	deque <string> q;
	for(int i=0;i<gems.size();i++){
		string gem=gems[i];
		q.push_back(gem);
		End++;
		if(check.find(gem)==check.end()) check[gem]=1;
		else check[gem]++;
		string front;
		while(check.size()==table.size()){
			front=q.front();
			q.pop_front();
			if(check[front]==1) check.erase(check.find(front));
			else check[front]--;
			if(check.size()<table.size()){
				q.push_front(front);
				check[front]=1;
				Start=End-(q.size()-1);
				break;
			}
		}
		if(check.size()==table.size()&&minVal>q.size()){
			answer.clear();
			answer.push_back(Start-1);
			answer.push_back(End-1);
			minVal=q.size();
			Start=i+2;
			End=i+1;
		}
	}
	return answer;
}

int main ()
{
	vector <string> gems={"AA", "AB", "AC", "AA", "AC"};
	vector <int> answer=solution(gems);
	cout<<"start: "<<answer[0]<<" end: "<<answer[1]<<endl;
	return 0;
}
