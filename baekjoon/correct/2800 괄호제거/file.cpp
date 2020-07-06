#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#define endl '\n'
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int Open,Close;
	string expression;
	stack <int> parenthesis;
	vector <int> Opens,Closes;
	vector <string> expressions;
	
	cin>>expression;
	for(int i=0;i<expression.size();i++){
		char letter=expression[i];
		if(letter=='(') parenthesis.push(i);
		else if(letter==')'){
			Opens.push_back(parenthesis.top());
			parenthesis.pop();
			Closes.push_back(i);
		}
	}
	
	for(int Case=1;Case<=Opens.size();Case++){
		vector <int> index;
		for(int i=0;i<Opens.size()-Case;i++) index.push_back(0);
		for(int i=0;i<Case;i++) index.push_back(1);
		do{
			set <int> CheckTable;
			for(int i=0;i<index.size();i++){
				if(index[i]==1){
					CheckTable.insert(Opens[i]);
					CheckTable.insert(Closes[i]);
				}
			}
			string str="";
			for(int i=0;i<expression.size();i++){
				if(CheckTable.find(i)==CheckTable.end()){
					str+=string(1,expression[i]);
				}
			}
			expressions.push_back(str);
		}while(next_permutation(index.begin(),index.end()));
	}
	sort(expressions.begin(),expressions.end());
	expressions.erase(unique(expressions.begin(),expressions.end()),expressions.end());
	for(int i=0;i<expressions.size();i++) cout<<expressions[i]<<endl;
	return 0;
}
