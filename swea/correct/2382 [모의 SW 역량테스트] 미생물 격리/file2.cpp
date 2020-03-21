#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 110;

struct cluster{
	int r,c,num,dir;
	bool live;
	cluster(int _r,int _c,int _num,int _dir) : r(_r),c(_c),num(_num),dir(_dir),live(true){}
};

int testcase,size,due,numClusters;
int r,c,num,dir;
int maxIdx,maxVal,sum;
int dr[]={0,-1,1,0,0};
int dc[]={0,0,0,-1,1};

vector <cluster> clusters;
vector <int> map[MAX][MAX];

void Move(){
	for(int i=0;i<numClusters;i++)	map[clusters[i].r][clusters[i].c].clear();
	for(int i=0;i<numClusters;i++){
		if(clusters[i].live){
			clusters[i].r+=dr[clusters[i].dir];
			clusters[i].c+=dc[clusters[i].dir];
			map[clusters[i].r][clusters[i].c].push_back(i);
		}
	}
}

void Arrange(){
	for(int i=0;i<numClusters;i++){
		if(clusters[i].live){
			if(clusters[i].r==0||clusters[i].r==size-1||clusters[i].c==0||clusters[i].c==size-1) {
				if(clusters[i].dir%2==0) clusters[i].dir-=1;
				else clusters[i].dir+=1;
				clusters[i].num/=2;
				if(clusters[i].num==0) clusters[i].live=false;
			}
			for(int j=0;j<numClusters;j++){
				if(map[clusters[j].r][clusters[j].c].size()>1){
					maxIdx=-1;maxVal=0;sum=0;
					for(int h=0;h<map[clusters[j].r][clusters[j].c].size();h++){
						int idx = map[clusters[j].r][clusters[j].c][h];
						sum+=clusters[idx].num;
						if(maxVal<clusters[idx].num){
							maxVal=clusters[idx].num;
							maxIdx=idx;
						}
					}
					for(int h=0;h<map[clusters[j].r][clusters[j].c].size();h++){
						int idx = map[clusters[j].r][clusters[j].c][h];
						if(idx!=maxIdx) clusters[idx].live = false;
					}
					map[clusters[j].r][clusters[j].c].clear();
					map[clusters[j].r][clusters[j].c].push_back(maxIdx);
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>testcase;
	for(int test=1;test<=testcase;test++){
		cin>>size>>due>>numClusters;
		for(int i=0;i<numClusters;i++){
			cin>>r>>c>>num>>dir;
			clusters.push_back(cluster(r,c,num,dir));
		}
		for(int i=0;i<due;i++){
			Move();
			Arrange();
		}
		int sum=0;
		for(int i=0;i<numClusters;i++){
			if(clusters[i].live) sum+=clusters[i].num;
		}
		cout<<"#"<<test<<" "<<sum<<endl;
	}
	return 0;
}
