#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll w, b, l = 0, h = 1e9, m, ans;
    cin >> w >> b;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (w + b >= m * (m + 1) / 2)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
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