#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3, M = 1e9 + 7;

ll dp[mxN + 1][mxN + 1];
string grid[mxN + 1];

int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> grid[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
                continue;
            }
            if (j)
            {
                dp[i][j] += dp[i][j - 1];
            }
            if (i)
            {
                dp[i][j] += dp[i - 1][j];
            }
            dp[i][j] %= M;
        }
    }
    cout << dp[r - 1][c - 1];
}