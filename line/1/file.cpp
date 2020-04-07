#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 각 괄호 플래그
char parent1,parent2,parent3,parent4;

int solution(string inputString) {
    int answer=-1;
    int cnt=0;

    for(int i=0;i<inputString.size();i++) {
        if(inputString[i] == '(') parent1++;
        else if(inputString[i] == ')'){
            if(!parent1) return answer;
            parent1--;
            cnt++;
        }
        if(inputString[i] == '{') parent2++;
        else if(inputString[i] == '}'){
            if(!parent2) return answer;
            parent2--;
            cnt++;
        }
        if(inputString[i] == '[') parent3++;
        else if(inputString[i] == ']') {
            if(!parent3) return answer;
            parent3--;
            cnt++;
        }
        if(inputString[i] == '<') parent4++;
        else if(inputString[i] == '>') {
            if(!parent4) return answer;
            parent4--;
            cnt++;
        }
    }
    if(parent1==0&&parent2==0&&parent3==0&&parent4==0) answer=cnt;

    return answer;
}
