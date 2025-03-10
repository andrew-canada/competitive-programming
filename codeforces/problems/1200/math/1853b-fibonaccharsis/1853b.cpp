#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int i1 = i, i2 = n;
        bool ok = 1;
        for (int j = 0; j < k - 2; j++)
        {
            int temp = i1;
            i1 = i2 - temp;
            i2 = temp;
            ok &= i1 <= i2;
            ok &= min(i1, i2) >= 0;
            if (!ok)
            {
                break;
            }
        }
        if (ok)
        {
            ans++;
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