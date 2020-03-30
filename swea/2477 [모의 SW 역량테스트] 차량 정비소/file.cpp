#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1000;

struct customer{
	int customerNum,arrive,receptNum,repairNum,receptTime,repairTime;
	bool done;
	customer(int _arrive) : customerNum(0), arrive(_arrive), receptNum(0),/
	repairNum(0), receptTime(0), repairTime(0), done(false){}
};

struct reception{
	int duration;
	bool empty;
	reception(int _duration) : duration(_duration), empty(true){}
};

struct repairment{
	int duration;
	bool empty;
	repairment(int _duration) : duration(int _duration), empty(true){}
};

vector <customer> customers;
vector <reception> receptions;
vector <repairment> repairments;

int testcase,numRecept,numRepair,numCustomer,receptA,repairB;
int receptTime,repairTime,customerTime;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		// 입력
		cin>>numRecept>>numRepair>>numCustomer>>receptA>>repairB;
		for(int i=0;i<numRecept;i++){
			cin>>receptTime;
			receptions.push_back(reception(receptTime));
		}
		for(int i=0;i<numRepair;i++){
			cin>>repairTime;
			repairments.push_back(repairment(repairTime));
		}
		for(int i=0;i<numCustomer;i++){
			cin>>customerTime;
			customers.push_back(customer(customerTime));
		}
		while(!allDone()){
			// 모든 손님의 창구 시간 == 창구 시간
			for(int i=0;i<numCustomer;i++){
				
			}
		}
	}
	return 0;
}

