#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

const int INF=987987987;

int numFrames,numVotes,vote;
int minVal;

vector <int> List;
map <int,pair<int,int> > frames;
map <int,pair<int,int> >::iterator minIter;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numFrames>>numVotes;
	
	for(int i=1;i<=numVotes;i++){
		cin>>vote;
		if(frames.find(vote)!=frames.end()){
			frames[vote].first++;
			frames[vote].second=i;
		}
		else{
			if(frames.size()<numFrames) frames[vote]=make_pair(1,i);
			else{
				minVal=INF;
				minIter=frames.begin();
				for(auto iter=frames.begin();iter!=frames.end();iter++){
					if(iter->second.first<minVal){
						minVal=iter->second.first;
						minIter=iter;
					}
					else if(iter->second.first==minVal){
						if(iter->second.second<minIter->second.second){ //ㅇㅕ기가 문제!
							minIter=iter;
						}
					}
				}
				frames.erase(minIter);
				frames[vote]=make_pair(1,i);
			}
		}
	}
	
	for(auto iter=frames.begin();iter!=frames.end();iter++){
		List.push_back(iter->first);
	}
	
	sort(List.begin(),List.end());
	for(int i=0;i<List.size();i++){
		cout<<List[i];
		if(i!=List.size()-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}
