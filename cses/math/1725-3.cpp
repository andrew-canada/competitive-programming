#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

const int mxN = 100, M = 1e9 + 7;

double dp[mxN + 1][6 * mxN + 1];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                dp[i + 1][j + k] += dp[i][j] / 6;
            }
        }
    }
    double ans = 0;
    for (int i = a; i <= b; i++)
    {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
}