#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

// 자식 노드 개수
const int ALPHABETS = 26; 

// 문자를 숫자로 바꾸기
int char_to_index(char input){
	return input - 'a';
}

// trie 자료구조
struct Trie{
	Trie* children[ALPHABETS];
	int cnt;
	bool is_terminal;
	
	Trie() : is_terminal(false), cnt(1){
		memset(children, 0, sizeof(children));
	}
	
	~Trie(){
		for (int i = 0; i<ALPHABETS; i++){
			if (children[i])
				delete children[i];
		}
	}
	
    void insert(const char* key){
        if (*key == '\0')
            is_terminal = true;
        else{
            int index = char_to_index(*key);
            if (children[index] == NULL)
                children[index] = new Trie();
            else
                children[index]->cnt++;
            children[index]->insert(key + 1);
 
        }
    }
    int find(const char* key){
        int index =  char_to_index(*key);
        if (*key == '?'){
            int tmp = 0;
            for (int k = 0; k<ALPHABETS; k++){
                if (children[k] != NULL)
                    tmp += children[k]->cnt;
            }
            return tmp;
        }
        if (children[index] == NULL) return 0;
        if (*(key + 1) == '?') return children[index]->cnt;
        return children[index]->find(key + 1);
    }
};
 
// 접두,접미 trie 생성
Trie *root[10001];
Trie *root_rev[10001];
 
vector<int> solution(vector<string> words, vector<string> queries) {
    int len = queries.size();
    vector<int> answer(len, 0); // 0 초기화 
 
 
    for (int i=0;i<words.size();i++){
        int size = words[i].size();
 
        const char *c = words[i].c_str();
        if (root[size] == NULL) root[size] = new Trie();
        root[size]->insert(c);
 
 
        string reversed_string = words[i];
        reverse(reversed_string.begin(), reversed_string.end());
 
        const char *k = reversed_string.c_str();
        if (root_rev[size] == NULL) root_rev[size] = new Trie();
        root_rev[size]->insert(k);
 
    }
 
    int idx = 0;
 
    for (int i=0;i<queries.size();i++){
 
        int size = queries[i].size();
 
        if (queries[i][size - 1] == '?'){
            const char *c = queries[i].c_str();
 
            if (root[size] == NULL){ idx++; continue; }
            else answer[idx] = root[size]->find(c);
 
        }
        else{
            string re = queries[i];
            reverse(re.begin(), re.end());
            const char *k = re.c_str();
 
            if (root_rev[size] == NULL){ idx++; continue; }
            else answer[idx] = root_rev[size]->find(k);
        }
        idx++;
    }
 
    return answer;
}
