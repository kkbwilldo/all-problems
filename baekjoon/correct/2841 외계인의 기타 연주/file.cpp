#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int numScales,numFrets;
int line,fret;
int answer;

priority_queue <int> lines[7];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numScales>>numFrets;
	for(int i=0;i<numScales;i++){
		cin>>line>>fret;
		if(lines[line].empty()){
			answer++;
			lines[line].push(fret);
		}
		else{
			while(lines[line].empty()==false&&lines[line].top()>fret){
				answer++;
				lines[line].pop();
			}
			if(lines[line].empty()||lines[line].top()<fret){
				lines[line].push(fret);
				answer++;
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}
