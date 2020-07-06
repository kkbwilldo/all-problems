#include <iostream>
#include <vector>
#define ll long long
#define endl '\n'
using namespace std;

ll numClasses,totalVal,answer;
vector <ll> classes;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numClasses>>totalVal;
	
	for(int i=0;i<numClasses;i++){
		ll Class;
		cin>>Class;
		classes.push_back(Class);
	}
	
	for(int i=numClasses-1;i>=0;i--){
		if(totalVal/classes[i]){
			answer+=totalVal/classes[i];
			totalVal%=classes[i];
		}
	}
	
	cout<<answer<<endl;
	return 0;
}
