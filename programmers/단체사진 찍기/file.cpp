#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

char characters[]={'A','C','F','J','M','N','R','T'};
char line[8];
int answer;
bool visited[8];
map <pair<char,char>,pair<char,int> > dists;

void SetDist(vector <string> data){
	for(int i=0;i<data.size();i++){
		char first=data[i][0];
		char second=data[i][2];
		char op=data[i][3];
		int bound=data[i][4]-'0';
		dists[make_pair(first,second)]=make_pair(op,bound);
	}
}

bool Check(){
	for(auto iter=dists.begin();iter!=dists.end();iter++){
		char person1=iter->first.first;
		char person2=iter->first.second;
		char op=iter->second.first;
		int bound=iter->second.second;
		int idx1,idx2;
		for(int i=0;i<8;i++){
			if(line[i]==person1) idx1=i;
			else if(line[i]==person2) idx2=i;
		}
		int dist=abs(idx1-idx2)-1;
		if(op=='='&&dist!=bound) return false;
		else if(op=='<'&&dist>=bound) return false;
		else if(op=='>'&&dist<=bound) return false;
	}
	return true;
}

void AllCases(int depth,vector <string> data){
    if(depth==8){
        if(Check()) answer++;
        return;
	}
    for(int i=0;i<8;i++){
		if(visited[i]) continue;
		visited[i]=true;
		line[depth]=characters[i];
		AllCases(depth+1,data);
		visited[i]=false;
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	answer=0;
	memset(line,0,sizeof(line));
	memset(visited,0,sizeof(visited));
	dists.clear();
  SetDist(data);
	AllCases(0,data);
	return answer;
}

int main ()
{
	vector<string> data={"M~C<2","C~M>1"};
	int ans=solution(2,data);
	cout<<ans<<endl;
	return 0;
}
