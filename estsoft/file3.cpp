#include <vector>
#include <string>
using namespace std;

bool isOkay;
bool prevDown;

void Check(vector<int> &A){
	vector <string> diffs;
	isOkay=true;
	
	int diff=A[0]-A[1];
	if(diff==0){
		isOkay=false;
		return;
	}
	
	if(diff<0) diffs.push_back("goUp");
	else if(diff>0) diffs.push_back("goDown");

	for(int i=1;i<A.size()-1;i++){
		diff=A[i]-A[i+1];
		if(diff==0){
			isOkay=false;
			return;
		}
		if(diff<0&&diffs.back()=="goUp"){
			isOkay=false;
			return;
		}
		if(diff>0&&diffs.back()=="goDown"){
			isOkay=false;
			return;
		}
		if(diff<0) diffs.push_back("goUp");
		else if(diff>0) diffs.push_back("goDown");
	}
}

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int size = A.size();
	int cnt=0;
	Check(A);
	if(isOkay) return 0;
	for(int i=0;i<size;i++){
		int num=A[i];
		A.erase(A.begin()+i);
		Check(A);
		if(isOkay) cnt++;
		A.insert(A.begin()+i,num);
	}
	if(cnt==0) cnt=-1;
	return cnt;
}

