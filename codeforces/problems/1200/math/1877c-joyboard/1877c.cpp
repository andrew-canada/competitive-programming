#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1)
    {
        cout << "1\n";
    }
    else if (k == 2)
    {
        int ans = (m - n) / n;
        ans = max(ans, 0);
        if (m >= n)
        {
            ans = ans + n;
        }
        else
        {
            ans = ans + m;
        }
        cout << ans << '\n';
    }
    else if (k == 3)
    {
        int ans = (m - n) - (m - n) / n;
        ans = max(ans, 0);
        cout << ans << '\n';
    }
    else
    {
        cout << "0\n";
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