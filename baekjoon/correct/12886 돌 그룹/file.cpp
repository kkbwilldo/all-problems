#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <set>
#include <utility>
using namespace std;

const int MAX = 501;

int first,second,third;
int one,two,three;
int numbers[3];
bool notSame;

set<pair<pair<int,int>, int> > visited;
queue <pair<pair<int,int>,int> > q;

bool cmp(const int& a,const int& b){
	if(a>b) return true;
	else return false;
}

bool isNotSame(){
	for(int i=0;i<3;i++){
		for(int j=i+1;j<3;j++){
			if(numbers[i]!=numbers[j]) return true;
		}
	}
	return false;
}

void Move(string type){

	one = first;
	two = second;
	three = third;
	
	if(type=="first_third"){
		one-=three;
		three+=three;
	}
	else if(type=="first_second"){
		one-=two;
		two+=two;
	}
	else if(type=="second_third"){
		two-=three;
		three+=three;
	}
	
	numbers[0]=one;numbers[1]=two;numbers[2]=three;
	if(!isNotSame()){
		cout<<1<<endl;
		exit(0);
	}
	sort(numbers,numbers+3,cmp);
	if(visited.find(make_pair(make_pair(numbers[0],numbers[1]),numbers[2]))==visited.end()){
		q.push(make_pair(make_pair(numbers[0],numbers[1]),numbers[2]));
		visited.insert(make_pair(make_pair(numbers[0],numbers[1]),numbers[2]));
	}
	
	if(!isNotSame()){
		cout<<1<<endl;
		exit(0);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<3;i++) cin>>numbers[i];
	
	if(!isNotSame()){
		cout<<1<<endl;
		return 0;
	}

	sort(numbers,numbers+3,cmp); // 내림차순 
	
	visited.insert(make_pair(make_pair(numbers[0],numbers[1]),numbers[2]));
	q.push(make_pair(make_pair(numbers[0],numbers[1]),numbers[2]));
	while(!q.empty()){
		first = q.front().first.first;
		second = q.front().first.second;
		third = q.front().second;
		q.pop();
		// fisrt <-> third
		Move("first_third");	
		//cout<<numbers[0]<<" "<<numbers[1]<<" "<<numbers[2]<<endl;	
		// first <->second
		Move("first_second");
		//cout<<numbers[0]<<" "<<numbers[1]<<" "<<numbers[2]<<endl;
		// second <-> third
		Move("second_third");
		//cout<<numbers[0]<<" "<<numbers[1]<<" "<<numbers[2]<<endl;
	}

	cout<<0<<endl;
	return 0;
}
