#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define endl "\n"
using namespace std;

const int MAX=350;
const int SIZE=150;
 
struct cell{
	int r,c;
	int bornT;
	int activeT;
	int deadT;
	int indicator;
	bool notDead;    
	cell(int _r,int _c,int _indi,int curTime){
		r=_r+SIZE;
		c=_c+SIZE;
		indicator=_indi;
		notDead=true;
		bornT=curTime;
		activeT=bornT+indicator;
		deadT=0;
	}
};

int testcase;
int ROW,COL,cultureTime;
int indicator;
int cnt;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int map[MAX][MAX];
vector <cell> cells;
 

 
bool cmp(const cell &a,const cell &b){
    if (a.indicator > b.indicator) return true;
    return false;
}

void Kill(int curTime){
	for(int i=0;i<cells.size();i++){
		if(cells[i].deadT==curTime) cells[i].notDead = false;
	}
}
 
void Activate(int curTime){
	vector <cell> temp;
	for(int i=0;i<cells.size();i++){
		if(cells[i].notDead == false) continue;
		if(cells[i].activeT == curTime){
			int r = cells[i].r;
			int c = cells[i].c;
			int indi = cells[i].indicator;
			for (int j=0;j<4;j++){
				int nr=r+dr[j];
				int nc=c+dc[j];
				if(map[nr][nc]!=0) continue;
				cell newOne = cell(nr,nc,indi,curTime+1);
				newOne.deadT=newOne.activeT+newOne.indicator;
				temp.push_back(newOne);
			}
		}
	}
	if(temp.size()==0) return;
	sort(temp.begin(),temp.end(),cmp);

	for(int i=0;i<temp.size();i++){
		int r = temp[i].r;
		int c = temp[i].c;
		int indi = temp[i].indicator;

		if(map[r][c]!=0) continue;
		map[r][c]=indi;
		cells.push_back(temp[i]);
	}
}
 
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("input.txt", "r", stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		memset(map,0,sizeof(map));
		cells.clear();
		cnt=0;
		
		cin>>ROW>>COL>>cultureTime;
		for(int r=0;r<ROW;r++){
			for(int c=0;c<COL;c++){
				cin>>indicator;
				if(indicator){
					map[r+SIZE][c+SIZE]=indicator;
					cell newOne=cell(r,c,indicator,0);
					newOne.deadT=newOne.activeT*2;
					cells.push_back(newOne);
				}
			}
		}
		
		int curTime=0;
		while (1){
			if (curTime==cultureTime) break;
			cout<<"here1"<<endl;
			Kill(curTime);
			cout<<"here2"<<endl;
			Activate(curTime);
			cout<<"here3"<<endl;
			curTime++;
		}

		cnt=0;
		for(int i=0; i<cells.size();i++){
			if(cells[i].notDead==false) continue;
			if(cells[i].deadT==cultureTime) continue;
			if(cells[i].bornT==cultureTime + 1) continue;
			cnt++;
		}

		cout<<"#"<<test<<" "<<cnt<<endl;
	}

	return 0;
}
