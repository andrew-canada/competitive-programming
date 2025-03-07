#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int M = 1e9 + 7, mxN = 1e6;

int n, x, c[mxN + 1], dp[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (c[i] <= j)
            {
                dp[j] = min(dp[j], dp[j - c[i]] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
}