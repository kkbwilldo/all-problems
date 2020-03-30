#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 2600;
int lenS,lenQ;
int maxVal;
int DP[MAX];
string STRING;
string query;

int find(int idx){
	string temp;
	for(int i=0;i<lenQ;i++){
		temp[i]=STRING[idx+i];
	}temp[lenQ]='\0';
	//cout<<"temp:"<<temp<<"  query:"<<query<<endl;
	if(strcmp(temp,query)) return 0;
	else return 1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	getline(cin,STRING);
	getline(cin,query);
	
	cout<<STRING<<"--"<<query<<endl;
	
	lenS=strlen(STRING);
	lenQ=strlen(query);
	
	for(int i=lenS-1;i>=0;i--){
		if(lenS-i+1<lenQ) DP[i]=0;
		else DP[i]=max(find(i)+DP[i+lenQ],DP[i+1]);
	}
	
	for(int i=0;i<lenS;i++){
		//cout<<"DP["<<i<<"]="<<DP[i]<<" ";
		if(maxVal<DP[i]) maxVal=DP[i];
	}
	//cout<<endl;
	
	cout<<maxVal<<endl;
	
	return 0;
}
