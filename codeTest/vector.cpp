#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector <int> v(5);
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
	int size=v.size();
	for(int i=0;i<size;i++){
		v.push_back(i+1);
	}
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
