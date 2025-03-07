#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 36;

int dp[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                // dp[i][i + len - 1] = min(dp[i][i + len - 1], gcd(dp[i][i], dp[i][i + j]) + gcd(dp[i][i + j], dp[i + len - 1][i + len - 1]));
                dp[i][i + len - 1] = min(dp[i][i + len - 1], dp[i][i + j] + dp[i + j + 1][i + len - 1] + gcd(i + j, i + j + 1));
            }
        }
    }
    cout << dp[1][n];
}