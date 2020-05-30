#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
	vector <string> strs={"|\\_/|", "|q p|   /}", "( 0 )\"\"\"\\","|\"^\"`    |", "||_/=\\\\__|"};
	for(int i=0;i<strs.size();i++)
		cout<<strs[i]<<endl;
	return 0;
}
