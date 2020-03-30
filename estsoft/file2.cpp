#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int val,maxVal;

vector <vector<int> > table(100);

bool cmp(const int &a,const int &b){
	if(a>b) return true;
	return false;
}

int DigitSum(int num){
	string str=to_string(num);
	int size=str.size();
	int sum=0;
	for(int i=0;i<size;i++) sum+=str[i]-'0';

	return sum;
}

int solution(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        val = DigitSum(A[i]);
        table[val].push_back(A[i]);
    }
    for (int i = 0; i < table.size(); i++) {
        if (table[i].size() != 0) {
            sort(table[i].begin(), table[i].end(), cmp);
        }
    }

    for (int i = 0; i < table.size(); i++) {
        if (table[i].size() > 1) {
            int sum = table[i][0] + table[i][1];
            maxVal = max(maxVal, sum);
        }
    }

    if (maxVal == 0) {
        return -1;
    }
    return maxVal;
}



