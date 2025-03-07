#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e5, M = 1e9 + 7;

int dp[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, r, c;
    cin >> t;
    while (t--)
    {
        int used = 0;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> r >> c;
            used += (r == c ? 1 : 2);
        }
        int m = n - used;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= m; i++)
        {
            dp[i] = (dp[i - 1] + 2ll * (i - 1) * dp[i - 2] % M) % M;
        }
        cout << dp[m] << '\n';
    }
}