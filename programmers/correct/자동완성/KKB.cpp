#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int ALPHA = 26;

int char_to_idx(char a){
    return a-'a';
}

struct trie{
    int cnt;
    bool is_terminal;
    trie* child[ALPHA];
    
    trie():cnt(0),is_terminal(false){
        memset(child,0,sizeof(child));
    }
    ~trie(){
        for(int i=0;i<ALPHA;i++){
            delete child[i];
        }
    }
    
    void insert(const char* key){
        if(*key=='\0') is_terminal=true;
        else{
            int idx=char_to_idx(*key);
            if(child[idx]==0) child[idx]= new trie();
            child[idx]->cnt++;
            child[idx]->insert(key+1);            
        }
    }
    
    int find(const char* key,const int Count){
        int idx=char_to_idx(*key);
        if(*key=='\0') return Count-1;
        if(child[idx]==0) return Count-1;
        if(child[idx]->cnt==1) return Count;
        return child[idx]->find(key+1,Count+1);
    }
};



int solution(vector<string> words) {
    int answer = 0;
    trie* root = new trie();
    for(int i=0;i<words.size();i++){
        root->insert(words[i].c_str());
    }
    for(int i=0;i<words.size();i++){
        answer+=root->find(words[i].c_str(),1);
    }
    return answer;
}
