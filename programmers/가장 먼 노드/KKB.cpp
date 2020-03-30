#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 20001;

int maxVal;
int dists[MAX];
bool visited[MAX];

vector <int> adjList[MAX];

void bfs(int start){
    visited[start] = true;
    queue <pair<int,int> > q;
    q.push(make_pair(start,0));
    while(!q.empty()){
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        dists[cur] = dist;
        for(int i=0;i<adjList[cur].size();i++){
            int next = adjList[cur][i];
            int nextDist = dist+1;
            if(!visited[next]){
                visited[next] = true;
                maxVal = max(maxVal,nextDist);
                q.push(make_pair(next,nextDist));
            }
        }
    }
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++){
        adjList[edge[i][0]].push_back(edge[i][1]);
        adjList[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    for(int i=0;i<MAX;i++){
        if(dists[i]==maxVal){
            answer++;
        }
    }
    return answer;
}
