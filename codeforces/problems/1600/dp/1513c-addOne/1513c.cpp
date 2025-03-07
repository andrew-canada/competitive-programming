#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5, M = 1e9 + 7;
int dp[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        dp[i] = 2;
    }
    dp[9] = 3;
    for (int i = 10; i <= mxN; i++)
    {
        dp[i] = (dp[i - 9] + dp[i - 10]) % M;
    }

    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll ans = 0;
        while (n > 0)
        {
            int x = n % 10;
            ans += (m + x < 10 ? 1 : dp[m + x - 10]);
            ans %= M;
            n /= 10;
        }
        cout << ans << "\n";
    }
}