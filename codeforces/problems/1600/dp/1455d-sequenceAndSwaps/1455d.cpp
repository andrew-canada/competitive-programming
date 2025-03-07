#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 5e2;

int a[mxN + 1], dp[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (is_sorted(a, a + n))
        {
            cout << "0\n";
            continue;
        }
        memset(dp, INF, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            if (a[i] > x && (i == 0 || a[i - 1] <= x))
            {
                dp[i][x] = 1;
            }
            if (i < n - 1 && a[i] > a[i + 1])
            {
                break;
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= mxN; j++)
            {
                if (dp[i][j] == INF)
                {
                    continue;
                }
                if (i == n || (j <= a[i + 1] && is_sorted(a + i + 1, a + n)))
                {
                    ans = min(ans, dp[i][j]);
                }
                bool ok = true;
                for (int k = i + 1; k < n; k++)
                {
                    int pr = k == i + 1 ? j : a[k - 1];
                    if (ok && a[i] >= pr && a[i] < a[k])
                    {
                        dp[k][a[i]] = min(dp[k][a[i]], dp[i][j] + 1);
                    }
                    ok &= (a[k] >= pr);
                }
            }
        }
        if (ans == INF)
        {
            ans = -1;
        }
        cout << ans << '\n';
    }
}