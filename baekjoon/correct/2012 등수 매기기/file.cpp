#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define ull unsigned long long
using namespace std;

int numStudents,expect;
ull answer;
vector <int> expects;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numStudents;
	for(int i=0;i<numStudents;i++){
		cin>>expect;
		expects.push_back(expect);
	}
	
	sort(expects.begin(),expects.end());
	for(int i=0;i<numStudents;i++){
		answer+=abs(expects[i]-(i+1));
	}
	cout<<answer<<endl;
	return 0;
}
