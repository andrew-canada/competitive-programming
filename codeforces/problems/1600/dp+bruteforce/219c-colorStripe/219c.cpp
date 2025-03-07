#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 5e5, mxK = 26;

int dp[mxN + 1][mxK + 1], par[mxN + 1][mxK + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    memset(dp, INF, sizeof(dp));
    memset(par, -1, sizeof(par));

    for (int c = 0; c < k; c++)
    {
        dp[0][c] = (s[0] - 'A' != c);
    }

    for (int i = 1; i < n; i++)
    {
        for (int c = 0; c < k; c++)
        {
            for (int prev = 0; prev < k; prev++)
            {
                if (c != prev)
                {
                    int cost = dp[i - 1][prev] + (s[i] - 'A' != c);
                    if (cost < dp[i][c])
                    {
                        dp[i][c] = cost;
                        par[i][c] = prev;
                    }
                }
            }
        }
    }

    int ansNum = INF;
    int lastChar = -1;
    for (int c = 0; c < k; c++)
    {
        if (dp[n - 1][c] < ansNum)
        {
            ansNum = dp[n - 1][c];
            lastChar = c;
        }
    }

    string ansStr(n, 'A');
    for (int i = n - 1; i >= 0; i--)
    {
        ansStr[i] = 'A' + lastChar;
        lastChar = par[i][lastChar];
    }

    cout << ansNum << '\n';
    cout << ansStr << '\n';
}