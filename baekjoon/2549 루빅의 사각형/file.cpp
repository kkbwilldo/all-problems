#include <iostream>
#include <vector>
#include <tuple>
#define endl '\n'
using namespace std;

const int INF=987987987;

int answerCnt;
int playBoard[4][4];
int answerBoard[4][4];
bool visited[2+1][4+1][7+1];

vector <tuple<int,int,int> > answerVector;

void Copy(int origin[][4],int temp[][4]){
	for(int r=0;r<4;r++){
		for(int c=0;c<4;c++){
			temp[r][c]=origin[r][c];
		}
	}
}

bool Check(){
	for(int r=0;r<4;r++){
		for(int c=0;c<4;c++){
			if(answerBoard[r][c]!=playBoard[r][c]) return false;
		}
	}
	return true;
}

void Move(int type,int idx,int times){
	if(type==1){
		int temp[4];
		for(int i=0;i<4;i++) temp[i]=playBoard[idx-1][i];
		for(int i=0;i<4;i++) playBoard[idx-1][(i+times)%4]=temp[i];
	}
	else{
		int temp[4];
		for(int i=0;i<4;i++) temp[i]=playBoard[i][idx-1];
		for(int i=0;i<4;i++) playBoard[(i+times)%4][idx-1]=temp[i];
	}
}

void dfs(int depth,int numMoves,vector <tuple<int,int,int> > &v){
	if(depth>7) return;
	if(numMoves>answerCnt) return;
	if(Check()==true){
		if(answerCnt>numMoves){
			answerVector=v;
			answerCnt=numMoves;
			return;
		}
	}
	for(int type=1;type<=2;type++){
		for(int idx=1;idx<=4;idx++){
			for(int times=1;times<=3;times++){
				if(visited[type][idx][depth]) continue;
				visited[type][idx][depth]=true;
				int temp[4][4];
				Copy(playBoard,temp);
				Move(type,idx,times);
				v.push_back(make_tuple(type,idx,times));
				dfs(depth+1,numMoves+1,v);
				v.pop_back();
				visited[type][idx][depth]=false;
				Copy(temp,playBoard);
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	answerCnt=INF;
	int i=1;
	for(int r=0;r<4;r++){
		for(int c=0;c<4;c++){
			cin>>playBoard[r][c];
			answerBoard[r][c]=i;
			i++;
		}
	}
	vector <tuple<int,int,int> > v;
	dfs(0,0,v);
	cout<<answerVector.size()<<endl;
	for(int i=0;i<answerVector.size();i++){
		int type,idx,times;
		tie(type,idx,times)=answerVector[i];
		cout<<type<<" "<<idx<<" "<<times<<endl;
	}
	return 0;
}
