#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
    int size = nums.size();
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    answer = nums.size();
    if(answer>size/2) answer = size/2;
	return answer;
}
