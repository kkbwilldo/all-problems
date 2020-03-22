#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX = 13;

int size,numTrees,years;
int R,C,Age;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};
int Food[MAX][MAX];
int Add[MAX][MAX];

vector <int> dead;
vector <int>::size_type type;
vector <int> Map[MAX][MAX];

void SpringAndSummer(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			if(Map[r][c].size()==0) continue;
			sort(Map[r][c].begin(),Map[r][c].end());
			dead.clear();
			int idx=0;
			while(Map[r][c].begin()+idx!=Map[r][c].end()){
				int age=Map[r][c][idx];
				if(age>Food[r][c]){
					dead.push_back(age);
					Map[r][c].erase(Map[r][c].begin()+idx);
				}
				else{
					Map[r][c][idx]++;
					Food[r][c]-=age;
					idx++;
				}
			}
			for(type=0;type<dead.size();type++){
				int age=dead[type];
				Food[r][c]+=age/2;
			}
		}
	}
}

void Fall(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			for(type=0;type<Map[r][c].size();type++){
				int age=Map[r][c][type];
				if(age%5==0){
					for(int i=0;i<8;i++){
						int nr=r+dr[i];
						int nc=c+dc[i];
						if(nr<0||nr>=size||nc<0||nc>=size) continue;
						Map[nr][nc].push_back(1);
					}
				}
			}
		}
	}
}

void Winter(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			Food[r][c]+=Add[r][c];
		}
	}
}

void Init(){
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			Food[r][c]=5;
		}
	}
}

int Alive(){
	int cnt=0;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cnt+=Map[r][c].size();
		}
	}
	return cnt;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>size>>numTrees>>years;
	for(int r=0;r<size;r++){
		for(int c=0;c<size;c++){
			cin>>Add[r][c];
		}
	}
	for(int i=0;i<numTrees;i++){
		cin>>R>>C>>Age;
		Map[R-1][C-1].push_back(Age);
	}
	
	Init();
	
	for(int i=0;i<years;i++){
		SpringAndSummer();
		Fall();
		Winter();		
	}
	Alive();
	cout<<Alive()<<endl;
	return 0;
}
