/*
문자열의 공백이 검색되면 [Start,i-1]을 substring 하여
벡터 numbers에 푸쉬한다.

numbers를 정렬한 후 최소값과 최댓값을 정답 문자열에 더한다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector <int> numbers;
    int Start=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            numbers.push_back(stoi(s.substr(Start,i)));
            Start=i+1;
        }
        if(i==s.size()-1) numbers.push_back(stoi(s.substr(Start,i)));
    }
    sort(numbers.begin(),numbers.end());
    answer+=to_string(numbers[0])+" "+to_string(numbers[numbers.size()-1]);
    return answer;
}
