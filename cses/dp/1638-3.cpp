#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e3, mxX = 1e6, M = 1e9 + 7;

string grid[mxN];
int dp[mxN][mxN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    if (grid[0][0] == '.')
    {
        dp[0][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
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
    }
    cout << dp[n - 1][n - 1];
}