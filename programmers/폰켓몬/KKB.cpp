#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
    int size = nums.size();
    vector <int> poke;
    for(int i=0;i<size/2;i++) poke.push_back(0);
    for(int i=size/2;i<size;i++) poke.push_back(1);
    set <int> type;
    do{
        type.clear();
        for(int i=0;i<size;i++){
            if(poke[i]==0){
                type.insert(nums[i]);
            }
            int cnt = type.size();
            answer = max(answer,cnt);
            if(answer==size/2) break;
        }
    }while(next_permutation(poke.begin(),poke.end()));
    
	return answer;
}
