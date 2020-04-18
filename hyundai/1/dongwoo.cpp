#include <bits/stdc++.h>
using namespace std;

int dp[50][3];

int solution(int n) {
    int answer = 0;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;
    dp[4][1] = 1;
    dp[5][1] = 1;
    dp[6][2] = 1;
    for (int i = 0; i <= n; i++) {
        // 현재 부화된 닭걀
        int egg = dp[i][1];

        // 당일하고 다음날에 추가
        dp[i][0] += egg;
        dp[i + 1][0] += egg;
        // 부화
        dp[i + 2][1] += egg;
        dp[i + 3][1] += egg;
        dp[i + 4][1] += egg;
        dp[i + 5][1] += egg;
        // 더이상 못낳음
        dp[i + 6][2] += egg;
        // 이전부터 못낳았던 친구들
        dp[i + 6][2] += dp[i + 5][2];
    }

    for (int i = 0; i < 3; i++) {
        answer += dp[n][i];
    }

    for (int i = 0; i <= n; i++) {
        cout << dp[i][0] << " ";
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {
        cout << dp[i][1] << " ";
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {
        cout << dp[i][2] << " ";
    }
    cout << endl;

    return answer;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    return 0;
}
