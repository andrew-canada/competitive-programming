#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 5e3;

ll n, m, a[mxN + 1], dp[mxN + 1];

void init()
{
    for (ll i = 0; i <= n; i++)
    {
        a[i] = 0;
        dp[i] = INF;
    }
    n = m = 0;
}

void solve()
{
    cin >> n;
    for (ll i = 1, x = 0; i <= n; i++)
    {
        cin >> x;
        if (x < n)
        {
            a[x]++;
        }
    }
    while (a[m])
    {
        m++;
    }
    dp[m] = 0;
    for (ll i = m; i >= 1; i--)
    {
        for (ll j = 0; j < i; j++)
        {
            dp[j] = min(dp[j], dp[i] + i * a[j]);
        }
    }
    cout << dp[0] - m << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, INF, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        init();
        solve();
    }
}