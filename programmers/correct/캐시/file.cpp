#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
const int INF=987987987;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	unordered_map <string,int> cache;
	if(cacheSize==0) answer=cities.size()*5;
	else{
		for(int i=0;i<cities.size();i++){
			if(cache.find(cities[i])==cache.end()){
				answer+=5;
				if(cache.size()<cacheSize) cache[cities[i]]=i;
				else{
					int minVal=INF;
					unordered_map <string,int>::iterator idx;
					for(auto iter=cache.begin();iter!=cache.end();iter++){
						if(minVal>iter->second){
							minVal=iter->second;
							idx=iter;
						}
					}
					cache.erase(idx);
					cache[cities[i]]=i;
				}
			}
			else{
				answer+=1;
				cache[cities[i]]=i;
			}
		}
	}
	return answer;
}

int main (){
	vector <string> cities={"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
	int cacheSize=3;
	int answer=solution(cacheSize,cities);
	cout<<answer<<endl;
	return 0;
}


