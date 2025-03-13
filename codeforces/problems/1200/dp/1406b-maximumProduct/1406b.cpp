#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll maxVal = -INF;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
    sort(a.begin(), a.end(), [](ll x, ll y)
         { return abs(x) > abs(y); });
    if (maxVal < 0)
    {
        cout << a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5] << '\n';
        return;
    }
    ll ans = a[0] * a[1] * a[2] * a[3] * a[4];
    for (int i = 5; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ll cur = a[i];
            for (int k = 0; k < 5; k++)
            {
                if (k != j)
                {
                    cur *= a[k];
                }
            }
            ans = max(ans, cur);
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