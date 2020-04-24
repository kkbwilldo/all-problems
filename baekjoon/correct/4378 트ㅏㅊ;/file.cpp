#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

string keyBoard[4]={"`1234567890-=",
									"QWERTYUIOP[]\\",
									"ASDFGHJKL;'",
									"ZXCVBNM,./"};
string str;

char GetOutput(int key){
	if(key==' ') return key;
	for(int i=0;i<4;i++){
		string line=keyBoard[i];
		for(int j=0;j<line.size();j++){
			if(line[j]==key) return line[j-1];
		}
	}
	return -1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	while(getline(cin,str)){
		for(int i=0;i<str.size();i++) cout<<GetOutput(str[i]);
		cout<<endl;
	}
	return 0;
}
