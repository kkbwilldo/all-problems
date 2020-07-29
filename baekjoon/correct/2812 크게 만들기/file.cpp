#include <iostream>
#include <string>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

int digit,erase;
string num;
vector <int> nums,answer;
stack <int> s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("input.txt","r",stdin);

	cin>>digit>>erase>>num;
	// num=11119999, erase=4
	// num=99991111, erase=4
	s.push(num[0]-'0');
	for(int i=1;i<digit;i++){
		int Next=num[i]-'0';
		while(!s.empty()&&erase>0&&s.top()<Next){
			erase--;
			s.pop();
		}
		s.push(Next);
	}

	while(erase>0){
		s.pop();
		erase--;
	}

	while(!s.empty()){
		answer.push_back(s.top());
		s.pop();
	}

	for(int i=answer.size()-1;i>=0;i--) cout<<answer[i];
	cout<<endl;

	return 0;
}
