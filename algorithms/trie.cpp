#include <iostream>
#include <string.h>
using namespace std;

const int ALPHABETS = 26;

int char_to_index(char input){
	return input - 'a';
}

struct Trie{
	bool is_terminal;
	Trie* children[ALPHABETS];
	
	Trie() : is_terminal(false){
		memset(children,0,sizeof(children));
	}
	
	~Trie(){
		for(int i=0;i<ALPHABETS;i++){
			if(children[i]) delete children[i];
		}
	}
	
	void insert(const char* key){
		if(*key == '\0') is_terminal = true;
		else{
			int index = char_to_index(*key);
			if(children[index]==0) children[index] = new Trie();
			children[index]->insert(key+1);
		}
	}
	
	// key에 해당하는 문자열을 접두어(prefix)로 가지고 있는지 확. 있으면 접두어가 끝나는 끝부분 위치 반환
	Trie* find(const char* key){
		if(*key=='\0') return this;
		int index = char_to_index(*key);
		if(children[index]==0) return NULL;
		return children[index]->find(key+1);
	}
	
	
	bool string_exist(const char* key){
		if(*key=='\0'&&is_terminal) return true;
		int index = char_to_index(*key);
		if(children[index]==0) return false;
		return children[index]->string_exist(key+1);
	}
};

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	//freopen("input.txt","r",stdin);
	
	Trie* root = new Trie();
	//const char * words[5] = {"be", "bee", "can", "cat", "cd"};
	string words[5] = {"ebe", "bee", "can", "cat", "cd"};

	for(int i = 0; i < 5; ++i){
		char str[words[i].size()+1];
		strcpy(str,words[i].c_str());
		cout<<"insert : "<<words[i]<<endl;
		root->insert(str);
	}
	
	string str1 = (root->find("be") != 0) ? "Prefix Exist" : "Prefix Not Exist";
	string str2 = (root->string_exist("bee") != 0) ? "String Exist" : "String Not Exist";
	cout << str1 << " : be" << endl;
	
	cout << str2 << " : bee" << endl;
	
	delete root;
	
	return 0;
}









