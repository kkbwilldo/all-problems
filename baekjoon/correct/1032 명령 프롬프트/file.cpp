#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 51;

vector <string> strs;

int num,len;
string str;
bool eq;
char letter;
char ans[MAX];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>str;
		strs.push_back(str);
	}
	len = str.length();
	
	for(int i=0;i<len;i++){
		eq=true;
		for(int j=0;j<num-1;j++){
			letter = strs[j][i];
			if(strs[j][i]!=strs[j+1][i]){
				eq=false;
				break;
			}
		}
		if(eq){
			ans[i]=letter;
		}
		else{
			ans[i]='?';
		}
	}
	for(int i=0;i<len;i++) cout<<ans[i];
	cout<<'\n';
	
	return 0;
}
