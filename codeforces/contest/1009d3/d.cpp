#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF LLONG_MAX / 4
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    vector<array<ll, 2>> valid[m + 1];
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y <= r[i]; y++)
        {
            ll diff = sqrtl(r[i] * r[i] - y * y);
            valid[y].push_back({x[i] - diff, x[i] + diff});
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++)
    {
        vector<array<ll, 2>> &cur = valid[i];
        sort(cur.begin(), cur.end());
        ll l = -INF, r = -INF, temp = 0;
        for (int j = 0; j < cur.size(); ++j)
        {
            if (cur[j][0] <= r)
            {
                r = max(r, cur[j][1]);
            }
            else
            {
                if (r != -INF)
                {
                    temp += r - l + 1;
                }
                l = cur[j][0];
                r = cur[j][1];
            }
        }
        if (r != -INF)
        {
            temp += r - l + 1;
        }
        ans += temp * (i != 0 ? 2 : 1);
    }
    cout << ans << '\n';
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