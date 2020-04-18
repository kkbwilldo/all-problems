//4
#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<vector<string>> v, string id){
	unordered_map<string, vector<string>> hash;
	unordered_map<string, int> visit;
	for (int i = 0; i<v.size();i++){
	  hash[v[i][0]].push_back(v[i][1]);
	  hash[v[i][1]].push_back(v[i][0]);
	  visit[v[i][0]] = 0;
	  visit[v[i][1]] = 0;
	}
	int size = hash[id].size();
	visit.erase(id);
	for (int i = 0; i < size; i++){
	  visit.erase(hash[id][i]);
	}

	for (auto it = visit.begin(); it != visit.end(); it++){
		vector<string> t = hash[it->first];
		for (int i = 0; i < t.size(); i++){
			for (int j = 0; j < size; j++){
				if (t[i] == hash[id][j])
					visit[it->first]++;
			}
		}
	}
	int maxVal = 0;
	vector<string> result;
	for (auto it = visit.begin(); it != visit.end(); it++){
		if (maxVal < it->second){
			result.clear();
			maxVal = it->second;
			result.push_back(it->first);
		}
		else if (maxVal == it->second){
			result.push_back(it->first);
		}
	}
	sort(result.begin(), result.end());
	return result;
}
