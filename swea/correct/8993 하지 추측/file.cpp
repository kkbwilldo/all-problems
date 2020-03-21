/*
#include <iostream>
#include <set>
#define ll long long
#define endl '\n'
using namespace std;

ll testcase,num;
bool done;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(ll test=1;test<=testcase;test++){
		cin>>num;
		set <ll> visited;
		visited.insert(num);
		done=true;
		while(num>1){
			if(num%2==0) num/=2;
			else num=3*(num+1);
			if(visited.find(num)!=visited.end()){
				done=false;
				cout<<"#"<<test<<" NO"<<endl;
				break;
			}
			visited.insert(num);
		}
		if(done) cout<<"#"<<test<<" YES"<<endl;
	}
	
	return 0;
}
*/

#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

ll testcase,num;
bool done;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(ll test=1;test<=testcase;test++){
		cin>>num;
		done=true;
		while(num>1){
			if(num%2==0) num/=2;
			else {
				cout<<"#"<<test<<" NO"<<endl;
				done=false;
				break;
			}
		}
		if(done) cout<<"#"<<test<<" YES"<<endl;
	}
	
	return 0;
}
