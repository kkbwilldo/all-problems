#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=101;

int numApps,memory;
int app,cost;
int DP[MAX][MAX*MAX] // cos만큼 메모리가 확보되어 있을 때 현재 앱부터 확보 가능한 최대 메모리 양
vector <int> apps,costs;

//here번째 앱부터 고려했을 때, left의 비용으로 확보 가능한 최대 메모리의 양.
int solve(int here, int left){
	if(here == n) return 0;
	int &ret = dp[here][left];
	if(ret != -1) return ret;

	//here번째 앱을 끄지 않는다.
	ret = solve(here+1, left);

	//비용이 충분하다면 here번째 앱을 꺼본다
	if(left >= cost[here])
		ret = max(ret, memory[here] + solve(here+1, left-cost[here]));
	return ret;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numApps>>memory;
	for(int i=0;i<numApps;i++){
		cin>>app;
		apps.push_back(app);
	}
	for(int i=0;i<numApps;i++){
		cin>>cost;
		costs.push_back(cost);
	}

	
	
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, cost, m[101], c[101], dp[101][10001];
int func(int pos, int cos) {
	if (pos < 0)
		return 0;
	int &ret = dp[pos][cos];
	if (ret != -1)
		return ret;
	ret = func(pos - 1, cos);
	if (cos - c[pos] >= 0)
		ret = max(ret, func(pos - 1, cos - c[pos]) + m[pos]);
	return ret;
}
int main() {
    scanf("%d%d", &n, &cost);
    int lo = 0, hi = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &m[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        hi += c[i];
    }
    memset(dp, -1, sizeof(dp));
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (func(n - 1, mid) >= cost)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n", lo);
    return 0;
}


출처: https://jason9319.tistory.com/226 [ACM-ICPC 상 탈 사람]
