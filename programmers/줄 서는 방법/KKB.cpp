/*
시간 초과
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAX=23;

int numPeople,seqNum,seq;
int numbers[MAX];
bool visited[MAX];
vector <int> ans;

void Seq(int depth){
	if(depth==numPeople){
		seqNum++;
		if(seqNum==seq){
			for(int i=0;i<depth;i++) ans.push_back(numbers[i]);
		}
		return;
	}
	for(int i=1;i<=numPeople;i++){
		if(visited[i]) continue;
		visited[i]=true;
		numbers[depth]=i;
		Seq(depth+1);
		visited[i]=false;
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	numPeople=3;
	seq=5;
	seqNum=0;
	Seq(0);
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
