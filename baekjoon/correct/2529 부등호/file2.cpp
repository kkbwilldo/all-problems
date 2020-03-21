#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> &perm, vector<char> &sym){
	for(int i=0;i<sym.size();i++){
		if(sym[i]=='<' && perm[i] > perm[i+1]){
			return false;
		}
		if(sym[i]=='>' && perm[i] < perm[i+1]){
			return false;
		}
	}
	return true;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("input.txt","r",stdin);
	
	int numSym;
	cin>>numSym;
	vector<char> ineq(numSym);
	for(int i=0;i<ineq.size();i++){
		cin>>ineq[i];
	}
	vector<int> small(numSym+1);
	vector<int> big(numSym+1);
	for(int i=0;i<=numSym;i++){
		small[i]=i;
		big[i]=9-i;
	}
	
	do{
		if(check(small,ineq)) break;
	} while(next_permutation(small.begin(),small.end()));
	
	do{
		if(check(big,ineq)) break;
	} while(prev_permutation(big.begin(),big.end()));
	
	for(int i=0;i<big.size();i++){
		cout<<big[i];
	}
	cout<<'\n';
	
	for(int i=0;i<small.size();i++){
		cout<<small[i];
	}
	cout<<'\n';
	
	return 0;
}


