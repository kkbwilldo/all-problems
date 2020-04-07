#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 210;

int numIces,numOhNos;
int idx1,idx2;
int answer;
int OhNo[MAX][MAX];

int AllCases(){
	vector <int> indice;
	for(int i=0;i<numIces-3;i++) indice.push_back(0);
	for(int i=0;i<3;i++) indice.push_back(1);
	int cnt=0;
	do{
		vector <int> iceIdx;
		for(int i=0;i<indice.size();i++){
			if(indice[i]) iceIdx.push_back(i);
		}
		if(OhNo[iceIdx[0]][iceIdx[1]]) continue;
		if(OhNo[iceIdx[0]][iceIdx[2]]) continue;
		if(OhNo[iceIdx[1]][iceIdx[2]]) continue;
		cnt++;
	}while(next_permutation(indice.begin(),indice.end()));
	return cnt;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numIces>>numOhNos;
	for(int i=0;i<numOhNos;i++){
		cin>>idx1>>idx2;
		idx1--;idx2--;
		OhNo[idx1][idx2]=OhNo[idx2][idx1]=1;
	}
	answer=AllCases();
	cout<<answer<<endl;
	return 0;
}
