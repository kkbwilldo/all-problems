//5
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v, int k){
	int sum = 0;
	int maxVal = 0;
	queue<int> q;
	for (int i = 0; i < v.size(); i++){
		if (q.empty()&&k>0){
			q.push(v[i]);
			sum += v[i];
		}
		else{
			if (q.size() < k){
				q.push(v[i]);
				sum += v[i];
			}
			else{
				int t = q.front();
				sum -= t;
				q.pop();
				q.push(v[i]);
				sum += v[i];
			}
		}
		maxVal = maxVal < sum ? sum : maxVal;
	}
	return maxVal;
}
