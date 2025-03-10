#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, x, ans = 0;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        w[x]++;
    }
    for (int s = 2; s <= 2 * n; s++)
    {
        int cur = 0;
        for (int i = 1; i < (s + 1) / 2; i++)
        {
            if (s - i > n)
            {
                continue;
            }
            cur += min(w[i], w[s - i]);
        }
        if (s % 2 == 0)
        {
            cur += w[s / 2] / 2;
        }
        ans = max(ans, cur);
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