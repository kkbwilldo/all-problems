//3
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> prices) {
	int answer = 0;
	
	auto min_max = minmax_element(prices.begin(), prices.end());
	//min_max.first : 최소값
	//min_max.second : 최대값 
	answer = *min_max.second - *min_max.first;

	return answer;
}
