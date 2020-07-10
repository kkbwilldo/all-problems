#include <iostream>
#define endl '\n'
using namespace std;

const int FIVE=5;
const int THREE=3;
int gram,answer;
int fives,rest;
bool isAnswer;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>gram;
	fives=gram/FIVE;
	rest=gram-fives*FIVE;
	while(fives>=0){
		if(rest%THREE==0){
			isAnswer=true;
			answer=fives+rest/THREE;
			break;
		}
		else{
			fives--;
			rest=gram-fives*FIVE;
		}
	}
	if(isAnswer==false) answer=-1;
	cout<<answer<<endl;
	return 0;
}
