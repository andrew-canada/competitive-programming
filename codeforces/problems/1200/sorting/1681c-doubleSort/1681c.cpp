#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<array<int, 2>> ans;
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        int minA = INF, minB = INF;
        for (int j = i; j < n; j++)
        {
            minA = min(minA, a[j]);
            minB = min(minB, b[j]);
        }
        ok = 0;
        for (int j = i; j < n; j++)
        {
            if (minA == a[j] && minB == b[j])
            {
                if (i != j)
                {
                    ans.pb({i, j});
                }
                ok = 1;
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
        if (!ok)
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans.size() << '\n';
    for (const auto &[a, b] : ans)
    {
        cout << a + 1 << " " << b + 1 << '\n';
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