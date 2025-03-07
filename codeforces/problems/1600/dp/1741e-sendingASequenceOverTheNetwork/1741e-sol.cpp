#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define eb emplace_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (i + a[i] <= n && dp[i - 1])
            dp[i + a[i]] = true;
        if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1])
            dp[i] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
}

int main()
{
    int t;
    cin >> t;

    forn(tt, t)
    {
        solve();
    }
}