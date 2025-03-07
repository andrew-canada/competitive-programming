#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, l, r, sum = 0;
    cin >> n >> l >> r;
    vector<int> a(n + 1), dp(n + 1);
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (j < i)
        {
            j = i;
            sum = 0;
        }
        while (j < n && sum < l)
        {
            sum += a[j];
            ++j;
        }
        if (sum >= l && sum <= r)
        {
            dp[j] = max(dp[i] + 1, dp[j]);
        }
        sum -= a[i];
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}