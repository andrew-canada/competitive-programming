#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n + 1), a(n + 1);
    for (int i = n - k + 1; i <= n; i++)
    {
        cin >> v[i];
    }
    if (k == 1)
    {
        cout << "YES\n";
        return;
    }
    for (int i = n - k + 2; i <= n; i++)
    {
        a[i] = v[i] - v[i - 1];
    }
    if (!is_sorted(a.begin() + n - k + 2, a.end()) || v[n - k + 1] > a[n - k + 2] * (n - k + 1))
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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