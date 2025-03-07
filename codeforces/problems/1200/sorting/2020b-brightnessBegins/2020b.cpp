#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

void solve()
{
    ll k, l = 1, r = 2e18, m;
    cin >> k;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        ll n = m - ll(sqrtl(m));
        if (n >= k)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << '\n';
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