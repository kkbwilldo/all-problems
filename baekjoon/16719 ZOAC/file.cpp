#include <iostream>
#define endl '\n'
using namespace std;

const int MAX = 110;

int size,minIdx;
char minLetter;
string inputS;
bool visited[MAX];


int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>inputS;
	size=inputS.size();
	for(int i=0;i<size;i++){
		minLetter='Z'+1;
		for(int j=0;j<size;j++){
			if(visited[j]) continue;
			if(minLetter>inputS[j]){
				minLetter=inputS[j];
				minIdx=j;
			}
		}
		visited[minIdx]=true;
		for(int j=0;j<size;j++){
			if(visited[j]) cout<<inputS[j];
		}cout<<endl;
	}
	
	return 0;
}
