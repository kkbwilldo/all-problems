#include <iostream>
using namespace std;

const int MAX = 40010;

int numPort,maxVal;
int ports[MAX];
bool connected[MAX];

bool isOkay(int port){
	for(int i=1;i<port;i++){
		if(connected[i]){
			if(ports[i]>ports[port]) return false;
		}
	}	
	return true;
}

void design(int port, int numConnected){
	if(port==numPort+1){
		if(numConnected>maxVal) maxVal=numConnected;
	}
	else{
		for(int i=port;i<=numPort;i++){
			if(isOkay(i)){
				design(i+1,numConnected+1);
				connected[i]=true;
			}
			else{
				design(i+1,numConnected);
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPort;
	for(int i=1;i<=numPort;i++) cin>>ports[i];
	
	design(1,0);
	
	cout<<maxVal<<endl;
	return 0;
}

