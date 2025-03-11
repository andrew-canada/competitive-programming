#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    ll ans = 0;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i] - i; j <= n; j += a[i])
        {
            if (j <= i)
            {
                continue;
            }
            if (i + j == a[i] * a[j])
            {
                ans++;
            }
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