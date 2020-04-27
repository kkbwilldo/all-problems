//1
#include <bits/stdc++.h>
int solution(int n)
{
	int dp[3][100] = { 0 };
	dp[2][0] = 1;
	dp[2][1] = 1;
	for (int i= 2; i <= n; i++){
		if (i > 3) dp[0][i] = dp[1][i - 4];
		dp[1][i] = dp[1][i - 2] + dp[2][i - 2] - dp[0][i];
		dp[2][i] = dp[2][i - 1] + dp[1][i - 1]-dp[0][i];
	}
	return dp[0][n] + dp[1][n] + dp[2][n];
}
