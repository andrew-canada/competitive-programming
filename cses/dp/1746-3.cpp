#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e5, mxM = 100, M = 1e9 + 7;

int arr[mxN + 1];
ll dp[mxN + 1][mxM + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0][arr[0]] = 1;
    if (arr[0] == 0)
    {
        fill(dp[0], dp[0] + m + 1, 1);
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (j > 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j < m)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= M;
            }
        }
        else
        {
            dp[i][arr[i]] += dp[i - 1][arr[i]];
            if (arr[i] > 1)
            {
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
            }
            if (arr[i] < m)
            {
                dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
            }
            dp[i][arr[i]] %= M;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= M;
    }
    cout << ans;
}