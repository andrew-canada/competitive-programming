#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, q, k;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        ll val1 = (n + 1) * (n + 1) - 4 * (k + 1);
        ll val2 = n * n - 4 * k;
        ll c = 0;
        if (val1 >= 0 && (sqrt(val1) == floor(sqrt(val1))))
        {
            if (val1 == 0)
            {
                c++;
            }
            else
            {
                c += 2;
            }
        }
        if (val2 >= 0 && floor(sqrt(val2) == floor(sqrt(val2))))
        {
            int j1 = (n + (ll)sqrt(val2)) / 2;
            int j2 = (n - (ll)sqrt(val2)) / 2;
            if (j1 != j2)
            {
                c += (a[j1] - a[j1 - 1] - 1) + (a[j2] - a[j2 - 1] - 1);
            }
            else
            {
                c += (a[j1] - a[j1 - 1] - 1);
            }
        }
        cout << c << ' ';
    }
    cout << '\n';
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