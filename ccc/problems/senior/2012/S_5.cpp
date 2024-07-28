#include <bits/stdc++.h>

using namespace std;

bool cat[26][26];
int dp[26][26];

int main()
{
    int r, c, n;
    cin >> r >> c >> n;
    int r1, c1;
    for (int i = 0; i < n; i++)
    {
        cin >> r1 >> c1;
        cat[r1][c1] = true;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (!cat[i][j])
            {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[r][c];
}