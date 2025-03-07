#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7, mxN = 1e3;

int t, n, k;
int dp[mxN + 1][mxN + 1][2];

int solve(int cur, int k, bool dir)
{
    if (k == 1)
    {
        return 1;
    }
    if (dp[cur][k][dir] != -1)
    {
        return dp[cur][k][dir];
    }

    int ans = 2;
    if (dir)
    {
        if (cur < n)
        {
            ans = (ans + solve(cur + 1, k, dir) - 1) % M;
        }
        if (cur > 1)
        {
            ans = (ans + solve(cur - 1, k - 1, !dir) - 1) % M;
        }
        dp[cur][k][dir] = ans;
    }
    else
    {
        if (cur > 1)
        {
            ans = (ans + solve(cur - 1, k, dir) - 1) % M;
        }
        if (cur < n)
        {
            ans = (ans + solve(cur + 1, k - 1, !dir) - 1) % M;
        }
        dp[cur][k][dir] = ans;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << '\n';
    }
}