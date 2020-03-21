#include <iostream>
using namespace std;

int testcase;
int len,result;
int zero,one,two,three,four,five,six,seven,eight,nine;
string STRING;

void init(){
	zero=one=two=three=four=five=six=seven=eight=nine=0;
}

void check(char num){
	if(num-'0'==0) zero++;
	else if(num-'0'==1) one++;
	else if(num-'0'==2) two++;
	else if(num-'0'==3) three++;
	else if(num-'0'==4) four++;
	else if(num-'0'==5) five++;
	else if(num-'0'==6) six++;
	else if(num-'0'==7) seven++;
	else if(num-'0'==8) eight++;
	else if(num-'0'==9) nine++;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>STRING;
		len=STRING.size();
		init();
		for(int idx=0;idx<len;idx++) check(STRING[idx]);
		result=zero%2+one%2+two%2+three%2+four%2+five%2+\
		       six%2+seven%2+eight%2+nine%2;
		cout<<"#"<<test<<" "<<result<<endl;
	}
	return 0;
}
