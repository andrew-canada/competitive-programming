#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, sum1 = 0, sum2 = 0, ans = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum1 += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sum2 += b[i];
    }
    sort(a.begin() + 1, a.end()), sort(b.begin() + 1, b.end());
    int x = n / 4, y = x;
    for (int i = 1; i <= x; i++)
    {
        sum1 -= a[i], sum2 -= b[i];
    }
    while (sum1 < sum2)
    {
        sum1 += 100;
        ans++;
        if ((ans + n) % 4)
        {
            if (y > 0)
            {
                sum2 += b[y--];
            }
        }
        else
        {
            if (x <= n)
            {
                sum1 -= a[++x];
            }
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