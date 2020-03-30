#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;

int idx1,idx2;
int numNames;
string name1,name2,name3;
string email;
string answer;

vector <string> emails;
vector <tuple<string,string,string> > names;

void ExtractNames(string &S){
	idx1=idx2=0;
	numNames=0;
	for(int i=0;i<S.size();i++){
		if(idx1>=S.size()) break;
		if(S[i]==';'){
			names.push_back(make_tuple(name1,name2,name3));
			cout<<name1<<" "<<name2<<" "<<name3<<" "<<endl;
			name1=name2=name3="";
			numNames=0;
			idx1=idx2=i+2;
			if(idx1>=S.size()) break;
			else continue;
		}
		if(S[i]!=' ') idx2++;
		else if(S[i]==' '){
			if(numNames==0) name1=S.substr(idx1,idx2);
			else if(numNames==1) name2=S.substr(idx1,idx2);
			else if(numNames==2) name3=S.substr(idx1,idx2);
			idx2++;
			idx1=idx2;
			numNames++;
		}
	}
}

void MakeEmails(string &C){
	for(int i=0;i<names.size();i++){
		tie(name1,name2,name3)=names[i];
		if(name3!="") name2=name3;
		email="<"+name2+"_"+name1+"@"+C+".com>";
		int cnt=1;
		for(int j=0;j<i;j++){
			if(emails[j]==email) cnt++;
		}
		if(cnt!=1){
			int idx=email.find('@');
			email=email.substr(0,idx)+to_string(cnt)+email.substr(idx+1,email.size());
		}
		emails.push_back(email);
	}
}

void MakeAnswer(){
	answer="";
	for(int i=0;i<names.size();i++){
		tie(name1,name2,name3)=names[i];
		answer+=name1+" "+name2+" "+name3+" "+emails[i]+"; ";
	}
	answer=answer.substr(0,answer.size()-2);
}

string solution(string &S, string &C) {
	ExtractNames(S);
	MakeEmails(C);
	MakeAnswer();
	/*
	for(int i=0;i<names.size();i++){
		tie(name1,name2,name3)=names[i];
		cout<<name1;
		cout<<" ";
		cout<<name2;
		cout<<" ";
		cout<<name3;
		cout<<endl;
	}
	*/
	//cout<<answer<<endl;
	return answer;
}

