#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

int a[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<ll>> dp(n + 1, vector<ll>(3));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));
            if (i + 2 <= n)
            {
                dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));
            }
            dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));
        }
        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    }
}
