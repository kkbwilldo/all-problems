/*
2가지 기준으로 정렬을 한다.
1. point 기준 정렬
2. idx 기준 정렬

벡터 scores에 점수와 인덱스를 저장하고
1번 기준으로 정렬한 후 총 점수 계산한다
2번 기준으로 정렬한 후 출력한다
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct score{
	int point,idx;
	score():point(0),idx(-1){}
	score(int _p,int _i):point(_p),idx(_i){}
};

int point,sum;

bool standard1(const score& a,const score& b){
	if(a.point>b.point) return true;
	return false;
}

bool standard2(const score& a, const score& b){
	if(a.idx<b.idx) return true;
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	vector <score> scores;
	for(int i=0;i<8;i++){
		cin>>point;
		scores.push_back(score(point,i+1));
	}
	sort(scores.begin(),scores.end(),standard1);
	scores.erase(scores.begin()+5,scores.end());
	for(int i=0;i<scores.size();i++) sum+=scores[i].point;
	cout<<sum<<endl;
	sort(scores.begin(),scores.end(),standard2);
	for(int i=0;i<scores.size();i++) cout<<scores[i].idx<<" ";
	cout<<endl;
	return 0;
}
