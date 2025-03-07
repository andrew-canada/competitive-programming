#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int x, n, ans = 1;
    cin >> x >> n;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (x / i >= n)
            {
                ans = max(ans, i);
            }
            if (i >= n)
            {
                ans = max(ans, x / i);
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