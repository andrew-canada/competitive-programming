#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m, ans = 0, num = 0;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> buc(n * m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            buc[a[i][j]] = max(buc[a[i][j]], 1);
            if (a[i - 1][j] == a[i][j] || a[i][j - 1] == a[i][j])
            {
                buc[a[i][j]] = 2;
            }
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        ans += buc[i], num = max(num, buc[i]);
    }
    cout << ans - num << '\n';
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
