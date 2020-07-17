#include <iostream>
#define endl '\n'
#define ll long long
using namespace std;

ll ROW,COL,answer;

ll min(ll a,ll b){
	if(a<=b) return a;
	return b;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>ROW>>COL;
	
	if(ROW==1){
		answer=1;
	}
	// 최대 4칸 이동 가능
	else if(ROW==2){
		answer=min((COL+1)/2,4);
	}
	else{
		/*
		COL==1: 1
		COL==2: 2
		COL==3: 3
		COL==4: 4
		COL==5: 4
		COL==6: 4
		*/
		if(COL<=6){
		 answer=min(COL,4);
		}
		else{
			/*
			오른쪽으로 2칸 이동하는 방법은 딱 2번만 쓰면 된다
			사용되지 않는 열은 2칸
			*/
			answer=COL-2;
		}
	}
	cout<<answer<<endl;
	return 0;
}
