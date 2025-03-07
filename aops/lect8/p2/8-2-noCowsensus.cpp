#include <bits/stdc++.h>

using namespace std;

double arr[201], dp[2][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    double ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int l = 0; l <= k; l++)
    {
        memset(dp[0], 0, sizeof(dp[0]));
        dp[0][0] = 1;
        bool next = 1;
        for (int c = 0; c < k; c++)
        {
            double cur = (c < l ? arr[c] : arr[n - c + l - 1]);
            memset(dp[next], 0, sizeof(dp[next]));
            for (int y = 0; y <= k / 2; y++)
            {
                if (dp[!next][y] == 0)
                {
                    continue;
                }
                if (y < k / 2)
                {
                    dp[next][y + 1] += cur * dp[!next][y];
                }
                dp[next][y] += (1 - cur) * dp[!next][y];
            }
            next = !next;
        }
        ans = max(ans, dp[!next][k / 2]);
    }
    cout << fixed << setprecision(9) << ans;
}