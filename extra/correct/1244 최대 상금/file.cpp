#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int testcase,numExchanges,size,maxVal;
string num;
bool visited[1000000][20]; // 6자리 수 갯수, 최대 교환횟수

vector <int> price;

int MakePrice(vector <int> price){
	int total=0;
	for(int i=0;i<price.size();i++){
		total+=price[i]*pow(10,size-1-i);
	}
	return total;
}

void AllCases(int depth,vector <int> price){
	if(depth==numExchanges){
		int result=MakePrice(price);
		maxVal=max(maxVal,result);
		return;
	}
	int curPrice=MakePrice(price); // 중복 제거,이거 안해서 틀렸다!!!!!!!!
	if(visited[curPrice][depth]) return; // 한번 방문한 숫자는 계속해서 방문 안할 거다!
	visited[curPrice][depth]=true; // 방문 취소 하지 않는다!!!!!!!!
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			int temp=price[i];
			price[i]=price[j];
			price[j]=temp;
			AllCases(depth+1,price);
			temp=price[i];
			price[i]=price[j];
			price[j]=temp;
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>num>>numExchanges;
		size=num.size();
		price.clear();
		memset(visited,0,sizeof(visited)); // 초기화 안해서 틀렸다
		for(int i=0;i<size;i++) price.push_back(num[i]-'0');
		maxVal=0;
		AllCases(0,price);
		cout<<"#"<<test<<" "<<maxVal<<endl;
	}
	return 0;
}
