#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

int numPillars;
int Left,height;
int Start,End;
int maxVal;

vector <tuple<int,int> > info;
vector <tuple<int,int> > fromLeft,fromRight;
vector <tuple<int,int> > answer;

bool cmp(const tuple<int,int> &a,const tuple<int,int> &b){
	return get<0>(a)<get<0>(b);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPillars;
	for(int i=0;i<numPillars;i++){
		cin>>Left>>height;
		info.push_back(make_tuple(Left,height));
		if(i==0) Start=Left;
		else if(i==numPillars-1) End=Left;
	}
	sort(info.begin(),info.end(),cmp);
	
	maxVal=0;
	for(int i=0;i<info.size();i++){
		tie(Left,height)=info[i];
		if(maxVal<height){
			maxVal=height;
			fromLeft.push_back(make_tuple(Left,maxVal));
		}
		else fromLeft.push_back(make_tuple(Left,maxVal));
	}
	
	maxVal=0;
	for(int i=info.size()-1;i>=0;i--){
		tie(Left,height)=info[i];
		if(maxVal<height){
			maxVal=height;
			fromRight.push_back(make_tuple(Left,height));
		}
		else fromRight.push_back(make_tuple(Left,maxVal));
	}
	
	for(int i=0;i<info.size();i++){
		int leftStart,leftHeight;
		int rightStart,rightHeight;
		tie(leftStart,leftHeight)=fromLeft[i];
		tie(rightStart,rightHeight)=fromRight[info.size()-1-i];
		if(leftHeight<rightHeight) answer.push_back(make_tuple(leftStart,leftHeight));
		else answer.push_back(make_tuple(rightStart,rightHeight));
	}
	
	int area=0;
	for(int i=0;i<info.size()-1;i++){
		int firstLeft,firstHeight;
		int secondLeft,secondHeight;
		tie(firstLeft,firstHeight)=answer[i];
		tie(secondLeft,secondHeight)=answer[i];
		area+=(secondLeft-firstLeft)*()
	}
	return 0;
}
