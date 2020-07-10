#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

const bool UP=true;

ll num,idx,row,col;
bool nextState=UP;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	
	/*
	01 02 06 07 15
	03 05 08 14
	04 09 13
	10 12
	11 
	
	1. col==1 이면 row++
	2. row==1 이면 up인지 down인지 판단
	3. up 이면 row--,col++
	4. down 이면 row++,col--
	*/
	
	row=col=idx=1;
	while(idx!=num){
		if(idx==1){
			col++;
			idx++;
			nextState=!UP;
		}
		else if(nextState==UP){
			if(row==1){
				col++;
				idx++;
				nextState=!UP;
			}
			else{
				row--;
				col++;
				idx++;
			}
		}
		else if(nextState==!UP){
			if(col==1){
				row++;
				idx++;
				nextState=UP;
			}
			else{
				row++;
				col--;
				idx++;
			}
		}
	}
	cout<<row<<"/"<<col<<endl;
	return 0;
}
