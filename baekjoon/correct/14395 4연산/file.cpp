#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
 
using namespace std;
 
bool exist;
long long int START, END;
string syms[] = { "*", "+", "-", "/" };
set<long long int> S;

long long int op(long long int idx, long long int type){
    if (type == 0) return (idx * idx);
    else if (type == 1) return (idx + idx);
    else if (type == 2) return (idx - idx);
    else if (type == 3) return (idx / idx);
}
 
string BFS() {
	queue<pair<long long int, string> > Q;
	Q.push(make_pair(START, ""));
	S.insert(START);
 
	while (Q.empty() == 0){
		long long int idx = Q.front().first;
		string s = Q.front().second;
		Q.pop();

		if (idx == END){
			exist = true;
			return s;
		}
		for (int i = 0; i < 4; i++){
			long long int next = op(idx, i);
			if (next < 1) continue;
			if (S.find(next) != S.end()) continue;
			S.insert(next);
			Q.push(make_pair(next, s + syms[i]));
		}
	}
	return "a";
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    freopen("input.txt", "r", stdin);
    
    cin >> START >> END;
		if (START == END) {
			cout << 0 << endl;
		    return 0;
		}
		string R = BFS();
		if (exist) cout << R << endl;
		else cout << "-1" << endl;
 
    return 0;
}

