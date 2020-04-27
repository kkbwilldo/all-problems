//2
#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<int> sequence){
	int answer = 0;
    int now = 1;
    for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] < now) {
			if (now - sequence[i] < sequence.size() - now + sequence[i])
				answer += now - sequence[i];
			else
				answer += sequence.size() - now + sequence[i];
		} 
		else {
			if (sequence[i] - now < now + sequence.size() - sequence[i])
				answer += sequence[i] - now;
			else
				answer += now + sequence.size() - sequence[i];
		}
		
		now = sequence[i];
	}
	return answer;
}

