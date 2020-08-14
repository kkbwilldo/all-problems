#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX=110;

int COL,type;
int board[MAX][MAX];

vector <vector <pair<int,int> > > types(8);

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	types[1]={{},{},{},{}};
	types[2]={{},{},{},{}};
	types[3]={{},{},{},{}};
	types[4]={{},{},{},{}};
	types[5]={{},{},{},{}};
	types[6]={{},{},{},{}};
	types[7]={{},{},{},{}};
	
	return 0;
}
