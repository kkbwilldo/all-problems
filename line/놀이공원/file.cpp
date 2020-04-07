#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numGroups,numTalls;
int groupSize;

vector <int> tallGates;

bool cmp(const int &a,const int &b){
  if(a>b) return true;
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin>>numGroups>>numTalls;
  for(int i=0;i<numGroups;i++){
    cin>>groupSize;
    if(i<numTalls) tallGates.push_back(groupSize);
    else{
      sort(tallGates.begin(),tallGates.end());
      tallGates[0]+=groupSize;
    }
  }
  sort(tallGates.begin(),tallGates.end(),cmp);
  cout<<tallGates[0]<<endl;
  return 0;
}
