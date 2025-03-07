#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 100;

int m[mxN + 1], s[mxN + 1];
int dp[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        memset(dp, -INF, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i][j] != -INF)
                {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + m[i] - (i + 1 < n ? s[i + 1] : 0));
                }
            }
        }

        int ans = -INF;
        for (int i = 0; i <= n; i++)
        {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << '\n';
    }
}