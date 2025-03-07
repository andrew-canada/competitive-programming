#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int a[mxN + 1];
bool dp[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (i + a[i] <= n && dp[i - 1])
            {
                dp[i + a[i]] = true;
            }
            if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1])
            {
                dp[i] = true;
            }
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
}