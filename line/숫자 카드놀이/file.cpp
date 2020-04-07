#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num,k;

vector <int> nums;

void FindKth(){
  sort(nums.begin(),nums.end());
  for(int i=0;i<k-1;i++) next_permutation(nums.begin(),nums.end());
}

void Print(){
  for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
  cout<<endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  
  for(int i=0;i<3;i++){
    cin>>num;
    nums.push_back(num);
  }
  cin>>k;
  FindKth();
  Print();
  return 0;
}
