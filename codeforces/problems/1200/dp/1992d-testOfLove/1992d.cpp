#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    vector<int> dp(n + 2, -1);
    dp[0] = k;
    for (int i = 1; i <= n + 1; i++)
    {
        if (i != n + 1 && s[i - 1] == 'C')
        {
            continue;
        }
        for (int t = 1; t <= m; t++)
        {
            if (i >= t && (i == t || s[i - t - 1] == 'L'))
            {
                dp[i] = max(dp[i], dp[i - t]);
            }
        }
        if (i > 1 && s[i - 2] == 'W')
        {
            dp[i] = max(dp[i], dp[i - 1] - 1);
        }
    }
    if (dp[n + 1] >= 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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