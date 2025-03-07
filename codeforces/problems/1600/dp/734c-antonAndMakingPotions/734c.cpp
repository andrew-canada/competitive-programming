#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e6;

int n, m, k, x, s;
int a[mxN + 1], b[mxN + 1], c[mxN + 1], d[mxN + 1];

int maxNum(int rem)
{
    int l = 0, r = k;
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (d[m] <= rem)
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }
    return c[l];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> x >> s;
    a[0] = x;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> d[i];
    }
    ll ans = 1LL * n * x;
    for (int i = 0; i <= m; i++)
    {
        int rem = s - b[i];
        if (rem < 0)
        {
            continue;
        }
        ans = min(ans, 1LL * (n - maxNum(rem)) * a[i]);
    }
    cout << ans << '\n';
}