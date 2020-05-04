#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int testcase,numSubjects,numSelects,score,maxVal;

vector <int> scores;

bool cmp(const int &a,const int &b){
	return a>b;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		scores.clear();
		maxVal=0;
		cin>>numSubjects>>numSelects;
		for(int i=0;i<numSubjects;i++){
			cin>>score;
			scores.push_back(score);
		}
		sort(scores.begin(),scores.end(),cmp);
		for(int i=0;i<numSelects;i++){
			maxVal+=scores[i];
		}
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
