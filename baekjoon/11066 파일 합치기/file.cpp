#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define ull unsigned long long
using namespace std;

int testcase,numChapters,size;
ull answer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>numChapters;
		vector <int> sizes;
		queue <int> q;
		answer=0;
		for(int i=0;i<numChapters;i++){
			cin>>size;
			sizes.push_back(size);
		}
		sort(sizes.begin(),sizes.end());
		for(int i=0;i<sizes.size();i++) q.push(sizes[i]);
		while(1){
			size=q.size();
			if(size==1) break;
			sizes.clear();
			for(int i=0;i<size-1;i+=2){
				int sum=0;
				sum+=q.front();
				q.pop();
				sum+=q.front();
				q.pop();
				answer+=sum;
				sizes.push_back(sum);
			}
			if(size%2==1){
				int num=q.front();
				q.pop();
				sizes.push_back(num);
			}
			sort(sizes.begin(),sizes.end());
			for(int i=0;i<sizes.size();i++) q.push(sizes[i]);
		}
		cout<<answer<<endl;
	}
	return 0;
}

