#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calendar[370];
int numDays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

vector <string> purchase;
vector <int> money;
vector <vector<int> > date;


void Init(vector <string> &purchase){
	purchase.push_back("2019/01/30 5000");
	purchase.push_back("2019/04/05 10000");
	purchase.push_back("2019/06/10 20000");
	purchase.push_back("2019/08/15 50000");
	purchase.push_back("2019/12/01 100000");
}

void Split(vector <string> &purchase){
	for(int i=0;i<purchase.size();i++){
		vector <int> temp;
		int Start=0,End=0;
		for(int j=0;j<purchase[i].size();j++){
			if('0'<=purchase[i][j]&&purchase[i][j]<='9') End++;
			else if(purchase[i][j]=='/'){
				int num=stoi(purchase[i].substr(Start,End-Start));
				temp.push_back(num);
				Start=End=j+1;
			}
			else if(purchase[i][j]==' '){
				int num=stoi(purchase[i].substr(Start,End-Start));
				temp.push_back(num);
				string str=purchase[i].substr(j+1,purchase[i].size()-j+1);
				num=stoi(str);
				money.push_back(num);
				break;
			}
		}
		date.push_back(temp);
	}
}

void SetCalendar(vector<string> purchase){
	for(int i=0;i<date.size();i++){
		int Start=0;
		for(int j=1;j<date[i][1];j++) Start+=numDays[j];
		Start+=date[i][2];
		for(int j=Start;j<Start+30;j++) calendar[j]+=money[i];
	}
}

vector <int> solution(vector<string> purchase){
	vector <int> answer(5,0);
	for(int i=1;i<=365;i++){
		if(calendar[i]<10000) answer[0]++;
		else if(calendar[i]<20000) answer[1]++;
		else if(calendar[i]<50000) answer[2]++;
		else if(calendar[i]<100000) answer[3]++;
		else answer[4]++;
	}
	return answer;
}

void Print(){
	for(int i=0;i<date.size();i++){
		cout<<"date: ";
		for(int j=0;j<3;j++){
			cout<<date[i][j]<<" ";
		}
		cout<<"money: "<<money[i]<<endl;
	}
}

int main (){
	Init(purchase);
	Split(purchase);
	SetCalendar(purchase);
	vector <int> answer;
	answer=solution(purchase);
	//Print();
	for(int i=0;i<answer.size();i++) cout<<answer[i]<<" ";
	cout<<endl;
	
	return 0;
}
