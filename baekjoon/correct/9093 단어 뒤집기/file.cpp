#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
using namespace std;

int numSentences;
string line,bufferflush;
vector <char> word;
vector <char>::reverse_iterator riter;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numSentences;
	getline(cin,bufferflush);
	for(int i=0;i<numSentences;i++){
		word.clear();
		getline(cin,line);
		for(int j=0;j<line.size();j++){
			if(line[j]==' '){
				for(riter=word.rbegin();riter!=word.rend();riter++) 
					cout<<*riter;
				cout<<" ";
				word.clear();
			}
			else word.push_back(line[j]);
			if(j==line.size()-1){
				for(riter=word.rbegin();riter!=word.rend();riter++)
					cout<<*riter;
				cout<<" ";
				word.clear();
			}
		}
		cout<<endl;
	}
	return 0;
}
