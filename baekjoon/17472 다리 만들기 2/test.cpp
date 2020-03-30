#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main ()
{
	vector <vector<pair<int,int> > > position;
	vector <pair<int,int> > temp;
	position.push_back(temp);
	position.push_back(temp);
	position[0].push_back(make_pair(1,2));
	position[1].push_back(make_pair(3,4));
	position[1].push_back(make_pair(20,40));
	position[0].push_back(make_pair(100,200));
	position[0].push_back(make_pair(10,20));
	cout<<position[0][0].first<<", "<<position[0][0].second<<endl;
	cout<<position[1][0].first<<", "<<position[1][0].second<<endl;
	cout<<position[1][1].first<<", "<<position[1][1].second<<endl;
	cout<<position[0][1].first<<", "<<position[0][1].second<<endl;
	cout<<position[0][2].first<<", "<<position[0][2].second<<endl;
	
	cout<<temp.size()<<endl;
	cout<<position.size()<<endl;
	cout<<position[0].size()<<endl;
	cout<<position[1].size()<<endl;

	return 0;
}
