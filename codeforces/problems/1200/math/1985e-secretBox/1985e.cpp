#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    ll x, y, z, k, ans = 0;
    cin >> x >> y >> z >> k;
    for (int a = 1; a <= x; a++)
    {
        for (int b = 1; b <= y; b++)
        {
            if (k % (a * b))
            {
                continue;
            }
            ll c = k / (a * b);
            if (c > z)
            {
                continue;
            }
            ll cur = (x - a + 1) * (y - b + 1) * (z - c + 1);
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
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
