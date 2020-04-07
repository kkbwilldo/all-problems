#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 55;

int numPlates,numNums,testcase;
int multiples,dir,jump;
int answer;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int board[MAX][MAX];
bool needAvg;
bool check[MAX][MAX];

void Rotate(int plateNum,int dir,int jump){
	vector <int> temp;
	for(int i=0;i<numNums;i++){
		temp.push_back(board[plateNum][i]);
	}
	for(int i=0;i<jump;i++){
		if(dir==0){
			temp.insert(temp.begin(),temp.back());
			temp.pop_back();
		}
		else{
			temp.push_back(temp[0]);
			temp.erase(temp.begin());
		}
	}
	for(int i=0;i<numNums;i++){
		board[plateNum][i]=temp[i];
	}
}

void FindAdj(){
	memset(check,0,sizeof(check));
	needAvg=true;
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			if(board[r][c]==0) continue;
			for(int i=0;i<4;i++){
				int nr=r+dr[i];
				int nc=c+dc[i];
				if(nc<0||nc>=numNums) nc=(nc+numNums)%numNums;
				else if(nr<0||nr>=numPlates) continue;
				if(board[r][c]==board[nr][nc]){
					check[r][c]=check[nr][nc]=true;
					needAvg=false;
				}
			}
		}
	}
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			if(check[r][c]) board[r][c]=0;
		}
	}
}

void GetAvg(){
	double avg=0,cnt=0;
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			if(board[r][c]==0) continue;
			avg+=board[r][c];
			cnt++;
		}
	}
	if(cnt==0) return;
	avg/=cnt;
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			if(board[r][c]==0) continue;
			if(board[r][c]>avg) board[r][c]--;
			else if(board[r][c]<avg) board[r][c]++;
		}
	}
}

int GetTotal(){
	int sum=0;
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			if(board[r][c]==0) continue;
			sum+=board[r][c];
		}
	}
	return sum;
}

void Print(){
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			cout<<board[r][c]<<" ";
		}cout<<endl;
	}cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numPlates>>numNums>>testcase;
	for(int r=0;r<numPlates;r++){
		for(int c=0;c<numNums;c++){
			cin>>board[r][c];
		}
	}
	//Print();
	for(int test=1;test<=testcase;test++){
		cin>>multiples>>dir>>jump;
		int temp=multiples;
		while(temp<=numPlates){
			Rotate(temp-1,dir,jump);
			temp+=multiples;
		}
		//Print();
		FindAdj();
		if(needAvg) GetAvg();
		//Print();
	}
	answer=GetTotal();
	cout<<answer<<endl;
	
	return 0;
}
