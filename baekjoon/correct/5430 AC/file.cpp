#include <iostream>
#include <string>
#include <queue>
#define endl '\n'
using namespace std;

char type;
int testcase,num,numDs;
string cmd,elements;

char R(char type){ 
	if(type=='R') return 'S'; // straight
	else return 'R';
}

void D(deque <int> &q,char type){
	if(type=='R') q.pop_back();
	else q.pop_front();
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		type='S';
		numDs=0;
		deque <int> q;
		cin>>cmd>>num>>elements;
		for(int i=0;i<cmd.size();i++){
			if(cmd[i]=='D') numDs++;
		}
		int idx=1;
		for(int i=1;i<elements.size()-1;i++){
			if(elements[i]==','){
				q.push_back(stoi(elements.substr(idx,i-idx)));
				idx=i+1;
			}
		}
		if(elements.size()>2){
			q.push_back(stoi(elements.substr(idx,elements.size()-1-idx)));
		}
		if(numDs>q.size()) cout<<"error"<<endl;
		else{
			for(int i=0;i<cmd.size();i++){
				if(cmd[i]=='R') type=R(type);
				else if(cmd[i]=='D') D(q,type);
			}
			cout<<"[";
			while(!q.empty()){
				if(type=='S'){
					cout<<q.front();
					q.pop_front();
					if(!q.empty()) cout<<",";
				}
				else{
					cout<<q.back();
					q.pop_back();
					if(!q.empty()) cout<<",";
				}
			}
			cout<<"]"<<endl;
		}
	}
	return 0;
}
