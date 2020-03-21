#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 13;

int testcase;
int day,month1,month3,year;
int minVal;
int plan[MAX];

void allCase(int startM,int startC){
	if(startM>=MAX) minVal = min(startC,minVal);
	else{
		allCase(startM + 1, startC + plan[startM]*day);
		allCase(startM + 1, startC + month1);
		allCase(startM + 3, startC + month3);
		allCase(startM + 12, startC + year);
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>day>>month1>>month3>>year;
		for(int i=1;i<MAX;i++) cin>>plan[i];
		minVal = year;
		allCase(1,0);
		cout<<"#"<<test<<" "<<minVal<<endl;
	}
	return 0;
}


