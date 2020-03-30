#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size());
    vector<string> 
    for(int q=0;q<queries.size();q++){
        bool prefix = true;
        if(queries[q][0]!='?') prefix = false;
        for(int w=0;w<words.size();w++){
            if( queries[q].size()==words[w].size()){
                bool notEqual = false;
                for(int h=0;h< queries[q].size();h++){
                    if( queries[q][h]=='?') {
                        if(prefix) continue;
                        else break;
                        }
                    else if( queries[q][h]!=words[w][h]){
                        notEqual = true;
                        break;
                    }
                }
                if(!notEqual) answer[q]++;
            }
        }
    }
    return answer;
}
