#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector <pair<double,double> > pos;
vector <double> tans;

bool cmp(const pair<double,double> &a,const pair<double,double> &b){
	if(a.first<b.first) return true;
	else if(a.first==b.first){
		if(a.second<b.second) return true;
		else return false;
	}
	return false;
}

double Calc(pair<double,double> first,pair<double,double> second){
	if((first.first==second.first)&&(first.second!=second.second)) return -1;
	if((first.first!=second.first)&&(first.second==second.second)) return -2;
	return (second.second-first.second)/(second.first-first.first);
}

void Print(){
	for(int i=0;i<tans.size();i++) cout<<tans[i]<<" ";
	cout<<endl;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	for(int i=0;i<3;i++){
		double x,y;
		cin>>x>>y;
		pos.push_back(make_pair(x,y));
	}
	sort(pos.begin(),pos.end(),cmp);
	
	for(int i=0;i<=2;i++){
		for(int j=i+1;j<=2;j++){
			double firstR,firstC,secondR,secondC;
			firstR=pos[i].first;firstC=pos[i].second;
			secondR=pos[j].first;secondC=pos[j].second;
			double tan=Calc(make_pair(firstR,firstC),make_pair(secondR,secondC));
			tans.push_back(tan);
		}
	}
	
	//Print();
	
	bool win=false;
	for(int i=0;i<=2;i++){
		for(int j=i+1;j<=2;j++){
			if(tans[i]!=tans[j]) win=true;
		}
	}
	
	if(win) cout<<"WINNER WINNER CHICKEN DINNER!"<<endl;
	else cout<<"WHERE IS MY CHICKEN?"<<endl;
	return 0;
}
