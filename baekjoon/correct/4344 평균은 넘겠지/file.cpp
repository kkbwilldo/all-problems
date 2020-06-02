#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	int testcase,numStudents,score;
	double avg,aboveAvg;
	vector <int> scores;
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numStudents;
		scores.clear();
		aboveAvg=avg=0;
		for(int i=0;i<numStudents;i++){
			cin>>score;
			scores.push_back(score);
			avg+=score;
		}
		avg/=scores.size();
		for(int i=0;i<numStudents;i++){
			if(scores[i]>avg) aboveAvg++;
		}
		cout<<fixed;
		cout.precision(3);
		cout<<(aboveAvg/scores.size())*100<<"%"<<endl;
	}
	return 0;
}
