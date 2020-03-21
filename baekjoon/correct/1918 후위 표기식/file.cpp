#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

int size;
string expression,answer;

stack <char> s;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>expression;
	size=expression.size();
	answer="";
	for(int i=0;i<size;i++){
		if('A'<=expression[i]&&expression[i]<='Z')
			answer+=expression[i];
		else{
			if(expression[i]=='(') s.push(expression[i]);
			else if(expression[i]==')'){
				while(!s.empty()&&s.top()!='('){
					answer+=s.top();
					s.pop();
				}
				s.pop();
			}
			else if(expression[i]=='*'||expression[i]=='/'){
				while(!s.empty()&&(s.top()=='*'||s.top()=='/')){
					answer+=s.top();
					s.pop();
				}
				s.push(expression[i]);
			}
			else if(expression[i]=='+'||expression[i]=='-'){
				while(!s.empty()&&s.top()!='('){
					answer+=s.top();
					s.pop();
				}
				s.push(expression[i]);
			}
		}
	}
	while(!s.empty()){
		answer+=s.top();
		s.pop();
	}
	cout<<answer<<endl;
	return 0;
}
