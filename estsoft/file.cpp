#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
	map <int,int> table;
	map <int,int>::iterator iter;
	maxVal=0;
	for(int i=0;i<A.size();i++){
		if(table.find(A[i])==table.end()) table[A[i]]=1;
		else table[A[i]]++;
	}
	for(iter=table.begin();iter!=table.end();iter++){
		if(iter->fisrt==iter->second){
			if(maxVal<iter->first) maxVal=iter->first;
		}
	}
	return maxVal;
}

