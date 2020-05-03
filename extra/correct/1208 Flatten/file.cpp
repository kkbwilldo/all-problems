#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=100;

int numDumps,numBoxes;
vector <int> boxes;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int test=1;test<=10;test++){
		boxes.clear();
		cin>>numDumps;
		for(int i=0;i<MAX;i++){
			cin>>numBoxes;
			boxes.push_back(numBoxes);
		}
		for(int i=0;i<numDumps;i++){
			sort(boxes.begin(),boxes.end());
			if(boxes[0]==boxes[MAX-1]) break;
			boxes[0]++;
			boxes[MAX-1]--;
		}
		sort(boxes.begin(),boxes.end());
		cout<<"#"<<test<<" "<<boxes[MAX-1]-boxes[0]<<endl;
	}
	return 0;
}
