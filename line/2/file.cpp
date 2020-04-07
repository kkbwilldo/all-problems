#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxWrong,first,second,serialSize,maxSize;

int solution(string answer_sheet, vector<string> sheets) { 
	int answer = -1;
    for(int i=0;i<sheets.size()-1;i++) {
        for(int j=i+1;j<sheets.size();j++) {
            int cnt=0;
            for(int k=0;k<answer_sheet.size();k++) {
				if(answer_sheet[k]!=sheets[i][k]&&sheets[i][k]==sheets[j][k]) cnt++;
			}
            if(maxWrong<cnt) {
				maxWrong=cnt;
				first=i;
				second=j;
			}
		}
	}
    if(!maxWrong) return 0;
    
    for(int i=0;i<answer_sheet.size();i++) {
        if(answer_sheet[i]!=sheets[first][i]&&sheets[first][i]==sheets[second][i]) serialSize++;
        else{
			maxSize=max(maxSize,serialSize);
			serialSize=0;
		}
	}
  maxSize=max(maxSize,serialSize);

  answer=maxWrong+maxSize*maxSize;
	return answer;
}


