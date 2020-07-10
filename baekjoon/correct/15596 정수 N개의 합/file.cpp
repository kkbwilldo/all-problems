#include <vector>
#define ll long long
using namespace std;

ll sum(vector <int> &a){
	ll answer=0;
	for(int i=0;i<a.size();i++){
		answer+=a[i];
	}
	return answer;
}
