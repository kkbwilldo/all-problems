#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	long double num,score,maxVal,sum;
	vector <long double> scores;
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>score;
		scores.push_back(score);
	}
	sort(scores.begin(),scores.end());
	maxVal=scores.back();
	sum=0;
	for(int i=0;i<scores.size();i++){
		scores[i]=(scores[i]/maxVal)*100;
		sum+=scores[i];
	}
	cout<<sum/scores.size()<<endl;
	return 0;
}
