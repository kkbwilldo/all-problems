#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int numDays,day;
vector <int> days;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	while(cin>>numDays){
		days.clear();
		for(int i=0;i<numDays;i++){
			cin>>day;
			days.push_back(day);
		}
		cout<<numDays<<endl;
		for(int i=0;i<numDays;i++) cout<<days[i]<<" ";
		cout<<endl;
	}
	return 0;
}
