#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX=10010;

int testcase,Start,End;
bool notPrimes[MAX];
bool visited[MAX];

void Eratosthenes(){
	notPrimes[0]=notPrimes[1]=true;
	for(int i=2;i<MAX;i++){
		if(notPrimes[i]) continue;
		int temp=i*i;
		while(temp<MAX){
			notPrimes[temp]=true;
			temp+=i;
		}
	}
}

int Calc(int num,int idx,int digit){
	if(idx==0)	return num%1000+digit*1000;
	else if(idx==1) return (num/1000)*1000+num%100+digit*100;
	else if(idx==2) return (num/100)*100+num%10+digit*10;
	else if(idx==3) return (num/10)*10+digit;
	return -1;
}

void ChangeDigits(){
	memset(visited,0,sizeof(visited));
	visited[Start]=true;
	queue <tuple<int,int> > q;
	q.push(make_tuple(Start,0));
	while(!q.empty()){
		int curNum,cnt;
		tie(curNum,cnt)=q.front();
		q.pop();
		if(curNum==End){
			cout<<cnt<<endl;
			return;
		}
		for(int idx=0;idx<4;idx++){
			for(int digit=0;digit<=9;digit++){
				int nextNum=Calc(curNum,idx,digit);
				if(nextNum==-1) continue;
				if(visited[nextNum]) continue;
				if(1000<=nextNum&&nextNum<10000){
					if(!notPrimes[nextNum]){
						visited[nextNum]=true;
						q.push(make_tuple(nextNum,cnt+1));
					}
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	Eratosthenes();
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>Start>>End;
		ChangeDigits();
	}
	
	return 0;
}
