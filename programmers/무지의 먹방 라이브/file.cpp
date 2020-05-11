#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int answer = 0;
map <int,int> table;

int solution(vector<int> food_times, long long k) {
	for(int i=0;i<food_times.size();i++) table[i+1]=food_times[i];
	map <int,int>::iterator iter;
	bool done=false;
	while(!done){
		iter=table.begin();
		while(iter!=table.end()){
			k--;
			iter->second--;
			//cout<<"cur iter : "<<iter->first<<endl;
			if(iter->second<=0){
				//cout<<" erased iter: "<<iter->first;
				table.erase(iter++);
				if(iter==table.end()) iter=table.begin();
				//cout<<" next iter: "<<iter->first<<endl;
			}
			else iter++;
			//if(k<=0) cout<<"k<=0"<<endl;
			//if(table.empty()) cout<<"table empty"<<endl;
			if(k<=0||table.empty()){
				done=true;
				if(table.empty()) answer=-1;
				else answer=iter->first;
				break;
			}
		}
	}
	return answer;
}

int main ()
{
	vector <int> foods={3,1,2};
	int ans=solution(foods,5);
	cout<<ans<<endl;
	return 0;
}
