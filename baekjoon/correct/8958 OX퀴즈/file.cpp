#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int testcase,score,cnt;
	string answer;
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>answer;
		cnt=score=0;
		for(int i=0;i<answer.size();i++){
			if(answer[i]=='O'){
				cnt++;
				score+=cnt;
			}
			else cnt=0;
		}
		cout<<score<<endl;
	}
	
	return 0;
}
