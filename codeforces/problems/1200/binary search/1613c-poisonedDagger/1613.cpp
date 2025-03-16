#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll l = 1, r = 1e18, m, ans;
    while (l <= r)
    {
        m = (l + r) / 2;
        ll sum = m;
        for (int i = 0; i < n - 1; i++)
        {
            sum += min(m, a[i + 1] - a[i]);
        }
        if (sum < h)
        {
            l = m + 1;
        }
        else
        {
            ans = m;
            r = m - 1;
        }
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