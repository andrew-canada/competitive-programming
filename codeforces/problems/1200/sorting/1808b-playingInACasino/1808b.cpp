#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[j][i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < n; j++)
        {
            ans += 1ll * j * a[i][j] - 1ll * (n - j - 1) * a[i][j];
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