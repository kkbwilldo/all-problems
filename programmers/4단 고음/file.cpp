#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer;
int pitch;

void dfs(int cnt,int prevPitch){
	if(prevPitch>pitch||cnt<0) return;
	if(prevPitch==pitch){
		if(cnt==0) answer++;
		return;
	}
	if(cnt>0) dfs(cnt-1,prevPitch+1);
	dfs(cnt+2,prevPitch*3);
}

int solution(int n){
	answer=0;
	dfs(2,3);
	return answer;
}

int main (){
	vector <int> pitchs={15,24,41,2147483647};
	for(int i=0;i<pitchs.size();i++){
		pitch=pitchs[i];
		int ans=solution(pitch);
		cout<<ans<<endl;
	}
	return 0;
}
