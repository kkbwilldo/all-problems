#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int k=4;
	string number="4177252841";
	string answer = "";
	vector <int> ans;
	for(int i=0;i<number.size();i++) ans.push_back(number[i]-'0');
	int idx=0;
	while(ans.size()>number.size()-k){
		if(ans[idx]<ans[idx+1]) ans.erase(ans.begin()+idx);
		else {
			if(idx>=ans.size()-k)	ans.erase(ans.begin()+idx);
			idx++;
		}
	}
	for(int i=0;i<ans.size();i++) answer+=char(ans[i]+'0');
	cout<<answer<<endl;
	return 0;
}
