#include <iostream>
#include <cstring>
using namespace std;

int num,answer,first,second,third;
string number;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=1;i<=num;i++){
		if(i<100){
			answer++;
			continue;
		}
		number=to_string(i);
		if(number.size()>=4) third=number[3]-number[2];
		if(number.size()>=3) second=number[2]-number[1];
		first=number[1]-number[0];
		if(number.size()>=4){
			if(third==second&&second==first) answer++;
		}
		else if(number.size()>=3){
			if(second==first) answer++;
		}
	}
	cout<<answer<<endl;
	return 0;
}
