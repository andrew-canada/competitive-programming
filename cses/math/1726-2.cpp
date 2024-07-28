#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxK = 100, mxX = 1e6, M = 1e9 + 7, mxS = 600;

double dp[mxK][8][8], prob[8][8];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            prob[i][j] = 1;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        dp[k][i1][j1] = 0;
                    }
                }
            }
            dp[0][i][j] = 1;
            for (int k = 0; k < n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        int nd = (i1 > 0) + (j1 > 0) + (i1 < 7) + (j1 < 7);
                        if (i1 > 0)
                        {
                            dp[k + 1][i1 - 1][j1] += dp[k][i1][j1] / nd;
                        }
                        if (j1 > 0)
                        {
                            dp[k + 1][i1][j1 - 1] += dp[k][i1][j1] / nd;
                        }
                        if (i1 < 7)
                        {
                            dp[k + 1][i1 + 1][j1] += dp[k][i1][j1] / nd;
                        }
                        if (j1 < 7)
                        {
                            dp[k + 1][i1][j1 + 1] += dp[k][i1][j1] / nd;
                        }
                    }
                }
            }
            for (int i1 = 0; i1 < 8; i1++)
            {
                for (int j1 = 0; j1 < 8; j1++)
                {
                    prob[i1][j1] *= (1 - dp[n][i1][j1]);
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ans += prob[i][j];
        }
    }
    cout << fixed << setprecision(6) << ans;
}