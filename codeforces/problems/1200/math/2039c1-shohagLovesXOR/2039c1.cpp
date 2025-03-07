#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, m, ans = 0;
    cin >> x >> m;
    for (int y = 1; y <= min(m, 2LL * x); y++)
    {
        if (x != y && (x % (x ^ y) == 0 || y % (x ^ y) == 0))
        {
            ans++;
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