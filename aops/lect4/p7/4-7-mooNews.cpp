#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 5e3;

int dp[mxN + 1][mxN + 1], len[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> len[i];
    }
    memset(dp, INF, sizeof(dp));

    for (int i = a; i <= b; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        int k = i;
        int tot = 0;
        while (k < n && tot + len[k] <= b)
        {
            tot += len[k];
            for (int j = a; j <= b; ++j)
            {
                if (tot >= j)
                {
                    dp[k + 1][j] = min(dp[k + 1][j], max(dp[i][j], tot - j));
                }
            }
            k++;
        }
    }

    int ans = INF;
    for (int i = a; i <= b; ++i)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
}
