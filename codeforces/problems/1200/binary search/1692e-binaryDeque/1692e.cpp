#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, s, ans = INF;
    cin >> n >> s;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = a[i];
        if (i)
        {
            p[i] += p[i - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1, m, pos = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (p[m] - (i ? p[i - 1] : 0) <= s)
            {
                pos = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (pos == -1 || p[pos] - (i ? p[i - 1] : 0) != s)
        {
            continue;
        }
        ans = min(ans, n - (pos - i + 1));
    }
    cout << (ans == INF ? -1 : ans) << '\n';
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