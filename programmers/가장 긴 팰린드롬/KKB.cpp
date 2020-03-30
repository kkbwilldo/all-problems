#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer=1;

    int size = s.size();
    if(size==1) return answer;
    for(int i=0;i<size;i++){
        for(int j=size-1;j>i;j--){
            if(j-i+1<answer) continue;
            if(s[i]==s[j]){
                string subStr = s.substr(i+1,j-1-(i+1)+1);
                string subRev = s.substr(i+1,j-1-(i+1)+1);
                reverse(subRev.begin(),subRev.end());
                if(subStr==subRev) {
                    answer=max(answer,j-i+1);
                    cout<<subStr<<" "<<subRev<<endl;
                }
                if(answer==size-i) return answer;
            }
        }
    }

    return answer;
}
