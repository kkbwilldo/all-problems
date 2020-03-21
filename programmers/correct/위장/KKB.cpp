/*
의상 종류 별로 몇 개의 옷이 있는지 카운트한다.
(각 의상의 개수+1)을 모두 곱한 후 
1가지 경우(모든 의상을 입지 않은 경우)를 뺀다.
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string,int> type;
    map <string,int>::iterator iter;
    for(int i=0;i<clothes.size();i++){
        string Key = clothes[i][1];
        if(type.find(Key)==type.end()) type[Key]=1;
        else type[Key]++;
    }
    for(iter=type.begin();iter!=type.end();iter++)
        answer*=(iter->second+1);
    answer-=1;
    return answer;
}


