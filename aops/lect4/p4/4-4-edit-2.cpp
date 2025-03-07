#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3;

int dp[mxN + 1][mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, chng, del, inst;
    string s1, s2;
    cin >> n >> m >> chng >> del >> inst >> s1 >> s2;

    // Initialize dp array
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i * del;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j * inst;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + chng;
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + del);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + inst);
        }
    }

    cout << dp[n][m] << '\n';
}