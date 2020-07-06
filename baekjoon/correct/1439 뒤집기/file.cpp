#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	char Refer;
	int ones=0,zeros=0,answer=0;
	string Input;
	
	cin>>Input;
	Refer=Input[0];
	for(int i=1;i<Input.size();i++){
		if(Input[i]!=Refer){
			if(Refer=='0'){
				zeros++;
				Refer=Input[i];
			}
			else if(Refer=='1'){
				ones++;
				Refer=Input[i];
			}
		}
	}
	if(Input.back()=='0') zeros++; // 여기 틀림
	else ones++;                   // 여기 틀림
	answer=min(zeros,ones);
	
	cout<<answer<<endl;
	return 0;
}
