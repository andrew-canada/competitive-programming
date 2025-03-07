#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

array<ll, 4> rect[20], dp[1 << 20];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> rect[i][0] >> rect[i][1] >> rect[i][2] >> rect[i][3];
    }
    for (ll i = 1; i < (1 << n); i++)
    {
        ll num = __builtin_popcount(i);
        ll l = -INF, d = -INF, r = INF, u = INF;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                l = max(l, rect[j][0]);
                d = max(d, rect[j][1]);
                r = min(r, rect[j][2]);
                u = min(u, rect[j][3]);
            }
        }
        ll cur = 0;
        if (l < r && d < u)
        {
            cur = (r - l) * (u - d);
        }
        if (num & 1)
        {
            ans += cur;
        }
        else
        {
            ans -= cur;
        }
    }
    cout << ans;
}