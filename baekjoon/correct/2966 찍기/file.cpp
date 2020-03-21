#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numProbs,maxVal;
char adrian[]={'A','B','C'};
char bruno[]={'B','A','B','C'};
char goran[]={'C','C','A','A','B','B'};
string problem;

vector <string> kids;

int Adrian(){
	int cnt=0;
	for(int i=0;i<numProbs;i++){
		if(adrian[i%3]==problem[i]) cnt++;
	}
	return cnt;
}

int Bruno(){
	int cnt=0;
	for(int i=0;i<numProbs;i++){
		if(bruno[i%4]==problem[i]) cnt++;
	}
	return cnt;
}

int Goran(){
	int cnt=0;
	for(int i=0;i<numProbs;i++){
		if(goran[i%6]==problem[i]) cnt++;
	}
	return cnt;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numProbs>>problem;
	maxVal=Adrian();
	kids.push_back("Adrian");
	if(maxVal<Bruno()){
		maxVal=Bruno();
		kids.clear();
		kids.push_back("Bruno");
	}
	else if(maxVal==Bruno()){
		kids.push_back("Bruno");
	}
	if(maxVal<Goran()){
		maxVal=Goran();
		kids.clear();
		kids.push_back("Goran");
	}
	else if(maxVal==Goran()){
		kids.push_back("Goran");
	}
	cout<<maxVal<<endl;
	for(int i=0;i<kids.size();i++) cout<<kids[i]<<endl;
	return 0;
}
