#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7, mxN = 1e3;

string grid[mxN];
ll dp[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    dp[0][0] = 1;
    if (grid[0][0] == '*')
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                continue;
            }
            if (i)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j)
            {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= M;
        }
    }
    cout << dp[n - 1][n - 1];
}