#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define ll long long
#define endl '\n'
using namespace std;

int testcase;
ll Top,Prev;
char op;
string str;

vector <ll> numbers;
stack <char> operators;

ll calc(ll Top,ll Prev,char op){
	if(op=='+') return Prev+Top;
	else return Prev*Top;
}

void PostExp(){
	numbers.clear();
	for(int i=0;i<str.size();i++){
		if('0'<=str[i]&&str[i]<='9') numbers.push_back(str[i]-'0');
		else if(str[i]=='(') operators.push(str[i]);
		else if(str[i]==')'){
			while(!operators.empty()&&operators.top()!='('){
				Top=numbers.back();
				numbers.pop_back();
				Prev=numbers.back();
				numbers.pop_back();
				op=operators.top();
				operators.pop();
				numbers.push_back(calc(Top,Prev,op));
			}
		}
		else if(str[i]=='+'){
			while(!operators.empty()&&operators.top()!='('){
				Top=numbers.back();
				numbers.pop_back();
				Prev=numbers.back();
				numbers.pop_back();
				op=operators.top();
				operators.pop();
				numbers.push_back(calc(Top,Prev,op));
			}
			operators.push('+');
		}
		else if(str[i]=='*'){
			while(!operators.empty()&&operators.top()=='*'){
				Top=numbers.back();
				numbers.pop_back();
				Prev=numbers.back();
				numbers.pop_back();
				op=operators.top();
				operators.pop();
				numbers.push_back(calc(Top,Prev,op));
			}
			operators.push('*');
		}
	}
	while(!operators.empty()){
		Top=numbers.back();
		numbers.pop_back();
		Prev=numbers.back();
		numbers.pop_back();
		op=operators.top();
		operators.pop();
		numbers.push_back(calc(Top,Prev,op));
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>str;
		PostExp();
		cout<<"#"<<test<<" "<<numbers[0]<<endl;
	}
	return 0;
}
