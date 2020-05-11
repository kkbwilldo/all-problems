#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int row=relation.size();
	int col=relation[0].size();
	bool visited[col];
	vector <int> notUnique;
	memset(visited,0,sizeof(visited));
	for(int c=0;c<col;c++){
		unordered_map <string,int> check;
		for(int r=0;r<row;r++){
			if(check.find(relation[r][c])==check.end())
				check[relation[r][c]]=1;
			else{
				notUnique.push_back(c);
				break;
			}
		}
	}
	int size=notUnique.size();
	answer+=col-size;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	for(int pick=1;pick<=col;pick++){
		vector <int> indice;
		for(int i=0;i<col-pick;i++) indice.push_back(0);
		for(int i=0;i<pick;i++) indice.push_back(1);
		do{
			bool leastKeys=true;
			bool isVisited=false;
			vector <int> relationIdx;
			for(int i=0;i<col;i++){
				if(indice[i]){
					if(visited[i]) {
						isVisited=true;
						break;
					}
					else relationIdx.push_back(i);
				}
			}
			if(isVisited) continue;
			unordered_map <string,int> table;
			for(int i=0;i<row;i++){
				string temp="";
				for(int j=0;j<relationIdx.size();j++){
					int idx=relationIdx[j];
					temp+=relation[i][idx];
				}
				if(table.find(temp)==table.end()) table[temp]=1;
				else{
					leastKeys=false;
					break;
				}
			}
			if(leastKeys){
				answer++;
				for(int i=0;i<relationIdx.size();i++){
					int idx=relationIdx[i];
					visited[idx]=true;
				}
			}
		}while(next_permutation(indice.begin(),indice.end()));
	}
	return answer;
}

int main ()
{
	vector <vector <string> > relation={{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};
	int answer=solution(relation);
	cout<<answer<<endl;
	return 0;
}
