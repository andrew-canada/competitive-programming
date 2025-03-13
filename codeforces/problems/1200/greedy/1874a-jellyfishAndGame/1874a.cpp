#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m, k, x = 0, y = 0;
    ll ans = 0;
    cin >> n >> m >> k;
    k--;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[x])
        {
            x = i;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (b[i] > b[y])
        {
            y = i;
        }
    }
    if (b[y] > a[x])
    {
        swap(a[x], b[y]);
    }
    if (k & 1)
    {
        x = 0, y = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[x])
            {
                x = i;
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (b[i] < b[y])
            {
                y = i;
            }
        }
        swap(a[x], b[y]);
    }
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
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