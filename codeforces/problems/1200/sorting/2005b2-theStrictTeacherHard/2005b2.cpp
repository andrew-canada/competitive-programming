#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m, q, b;
    cin >> n >> m >> q;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--)
    {
        cin >> b;
        int k = upper_bound(a.begin(), a.end(), b) - a.begin();
        if (k == 0)
        {
            cout << a[0] - 1 << '\n';
        }
        else if (k == m)
        {
            cout << n - a[m - 1] << '\n';
        }
        else
        {
            cout << (a[k] - a[k - 1]) / 2 << '\n';
        }
    }
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