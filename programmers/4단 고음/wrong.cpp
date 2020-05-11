#include <iostream>
#include <string>
using namespace std;

int answer;
int pitch;

int GetPitch(int curPitch,char type){
	if(type=='*') return curPitch*3;
	return curPitch+1;
}

bool Check(string notes){
	if(notes[0]!='*') return false;
	int cnt=0;
	for(int i=0;i<notes.size();i++){
		if(notes[i]=='*') cnt+=2;
		else cnt--;
		if(cnt<0) return false;
	}
	if(cnt>0) return false;
	return true;
}

void dfs(int cnt,int prevPitch,string notes){
	if(prevPitch>pitch||cnt<0) return;
	if(prevPitch==pitch){
		if(Check(notes)) answer++;
		return;
	}
	if(cnt>0){
		int curPitch=GetPitch(prevPitch,'+');
		string curNote=string(1,'+');
		dfs(cnt-1,curPitch,notes+curNote);
	}
	int curPitch=GetPitch(prevPitch,'*');
	string curNote=string(1,'*');
	dfs(cnt+2,curPitch,notes+curNote);
}

int solution(int n){
	answer=0;
    pitch=n;
	dfs(0,1,"");
	return answer;
}
