#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> arr1(n), arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    vector<int> r1(m), r2(m), c1(n), c2(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            r1[j] += (int)(arr1[i][j] - '0'), r1[j] %= 3;
            r2[j] += (int)(arr2[i][j] - '0'), r2[j] %= 3;
            c1[i] += (int)(arr1[i][j] - '0'), c1[i] %= 3;
            c2[i] += (int)(arr2[i][j] - '0'), c2[i] %= 3;
        }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        ok &= (c1[i] == c2[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ok &= (r1[i] == r2[i]);
    }
    cout << (ok ? "YES\n" : "NO\n");
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
