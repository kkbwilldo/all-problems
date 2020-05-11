#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector <string> possible[10];
set <string> check;

void dfs(int depth,int size){
	if(depth==size){
		string temp="";
		for(auto iter=check.begin();iter!=check.end();iter++){
			temp+=*iter;
		}
		if(visited.find(temp)==visited.end()){
			visited.insert(temp);
			answer++;
		}
		return;
	}
	for(int i=0;i<possible[depth].size();i++){
		string user=possible[depth][i];
		if(check.find(user)!=check.end()) continue;
		check.insert(user);
		dfs(depth+1,size);
		check.erase(check.find(user));
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	set <string> visited;
	for(int i=0;i<banned_id.size();i++){
		string banned=banned_id[i];
		int size=banned.size();
		for(int j=0;j<user_id.size();j++){
			string user=user_id[j];
			if(user.size()!=size) continue;
			bool ok=true;
			for(int h=0;h<size;h++){
				if(banned[h]=='*') continue;
				if(banned[h]!=user[h]){
					ok=false;
					break;
				}
			}
			if(ok) possible[i].push_back(user);
		}
	}
	for(int i=0;i<banned_id.size();i++){
		for(int j=0;j<possible[i].size();j++){
			cout<<possible[i][j]<<" ";
		}cout<<endl;
	}
	dfs(0,banned_id.size());
	return answer;
}

int main ()
{
	vector <string> user_id={"frodo", "fradi", "crodo", "abc123", "frodoc"};
	vector <string> banned_id={"*rodo", "*rodo", "******"};
	int ans=solution(user_id,banned_id);
	
	return 0;
}
