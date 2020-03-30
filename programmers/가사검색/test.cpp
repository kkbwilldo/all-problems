#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main ()
{
	string str = "testkkb";
	char strArr[str.size()+1];
	strcpy(strArr,str.c_str());
	cout<<strArr<<endl;
	reverse(str.begin(),str.end());
	cout<<str<<endl;
	return 0;
}
