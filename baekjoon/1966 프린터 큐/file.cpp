#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

int testcase,answer;
int numElements,idx,num,cur;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return a.first>b.first;
}

void Rotate(pair<int,int> &q){
	pair<int,int> front=q.front();
	q.pop();
	q.push(front);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numElements>>idx;
		queue <pair<int,int> > q;
		vector <pair<int,int> > v;
		pair<int,int> element,End;
		cur=0;
		for(int i=0;i<numElements;i++){
			cin>>num;
			element=make_pair(num,i);
			q.push(element);
			v.push_back(element);
			if(i==idx) End=element;
		}
		
		sort(v.begin(),v.end(),cmp);
		
		while(1){
			pair<int,int> front=q.front();
			if(front==v[cur]){
				if(front==End){
					
				}
				cur++;
				q.pop();
			}
		}
	}
	return 0;
}
