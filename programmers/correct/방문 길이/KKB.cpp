#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;

int solution(string dirs) {
	int answer = 0;
	set <pair<pair<pair<int,int>,pair<int,int> >,int > > visited;
	map <char,int> dir;
	int dr[]={-1,1,0,0};
	int dc[]={0,0,-1,1};
	dir['U']=0;dir['D']=1;dir['L']=2;dir['R']=3;
	int r,c;
	r=c=0;
	for(int i=0;i<dirs.size();i++){
		int idx=dir[dirs[i]];
		int nr=r+dr[idx];
		int nc=c+dc[idx];
		if(nr<-5||nr>5||nc<-5||nc>5) continue;
		if(visited.find(make_pair(make_pair(make_pair(nr,nc),make_pair(r,c)),idx))==visited.end()){
			int nextIdx;
			if(idx%2==0) nextIdx=idx+1;
			else nextIdx=idx-1;
			visited.insert(make_pair(make_pair(make_pair(nr,nc),make_pair(r,c)),idx));
			visited.insert(make_pair(make_pair(make_pair(r,c),make_pair(nr,nc)),nextIdx));
			answer++;
		}
		r=nr;
		c=nc;
	}
	return answer;
}
