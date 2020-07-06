#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int numApps,memory;
vector <pair<int,int> > apps;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>numApps>>memory;
	for(int i=0;i<numApps;i++){
		int app;
		cin>>app;
		apps.push_back(make_pair(app,0));
	}
	for(int i=0;i<numApps;i++){
		int cost;
		cin>>cost;
		apps[i].second=cost;
	}
	return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, cost, m[101], c[101], dp[101][10001];
int func(int pos, int cos) {
    if (pos < 0)return 0;
    int &ret = dp[pos][cos];
    if (ret != -1)return ret;
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
