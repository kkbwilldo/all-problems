#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAX = 110;

int R,C,val;
unsigned long lenRow,lenCol,Limit; //max,min 함수 때문에 unsigned long 사용
int board[MAX][MAX];
int answer;

void Print(){
	for(int r=0;r<lenRow;r++){
		for(int c=0;c<lenCol;c++){
			cout<<board[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

bool cmp(const pair <int,int> &a,const pair <int,int> &b){
	if(a.second<b.second) return true;
	else if(a.second==b.second){
		if(a.first<b.first) return true;
		else return false;
	}
	return false;
}

void Sort(string operation){
	if(operation=="ROW"){
		for(int r=0;r<lenRow;r++){
			unordered_map <int,int> howMany;
			vector <pair<int,int> > info;
			for(int c=0;c<lenCol;c++){
				if(board[r][c]==0) continue;
				if(howMany.find(board[r][c])==howMany.end())
					howMany[board[r][c]]=1;
				else
					howMany[board[r][c]]++;
			}
			for(auto iter=howMany.begin();iter!=howMany.end();iter++)
				info.push_back(make_pair(iter->first,iter->second));
			sort(info.begin(),info.end(),cmp);
			lenCol=max(lenCol,info.size()*2);
			lenCol=min(lenCol,Limit);
			for(int c=0;c<lenCol;c++) board[r][c]=0;
			for(int i=0;i<info.size();i++){
				if(2*i>=Limit) break;
				board[r][2*i]=info[i].first;
				board[r][2*i+1]=info[i].second;
			}
		}
	}
	else if(operation=="COL"){
		for(int c=0;c<lenCol;c++){
			unordered_map <int,int> howMany;
			vector <pair<int,int> > info;
			for(int r=0;r<lenRow;r++){
				if(board[r][c]==0) continue;
				if(howMany.find(board[r][c])==howMany.end())
					howMany[board[r][c]]=1;
				else
					howMany[board[r][c]]++;
			}
			for(auto iter=howMany.begin();iter!=howMany.end();iter++)
				info.push_back(make_pair(iter->first,iter->second));
			sort(info.begin(),info.end(),cmp);
			lenRow=max(lenRow,info.size()*2);
			lenRow=min(lenRow,Limit);
			for(int r=0;r<lenRow;r++) board[r][c]=0;
			for(int i=0;i<info.size();i++){
				if(2*i>=Limit) break;
				board[2*i][c]=info[i].first;
				board[2*i+1][c]=info[i].second;
			}
		}
	}
}

bool isItInRange(){
	if(R<lenRow&&C<lenCol) return true;
	return false;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>R>>C>>val;
	R--;C--;
	for(int r=0;r<3;r++){
		for(int c=0;c<3;c++){
			cin>>board[r][c];
		}
	}
	
	lenRow=lenCol=3;
	Limit=100;
	while(answer<=Limit){
		if(isItInRange()){
			if(board[R][C]==val) break;
		}
		if(lenRow>=lenCol) Sort("ROW");
		else Sort("COL");
		//Print();
		answer++;
	}
	
	if(answer>100) answer=-1; // 여기서 answer>=100 이라고 해서 틀림
	cout<<answer<<endl;
	
	return 0;
}
