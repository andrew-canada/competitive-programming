#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    ll n, m, h, ans = 1;
    cin >> n >> m >> h;
    array<ll, 2> best;
    for (int i = 0; i < n; i++)
    {
        ll tasks = 0, pen = 0, sum = 0;
        vector<ll> cur(m);
        for (int j = 0; j < m; j++)
        {
            cin >> cur[j];
        }
        std::sort(cur.begin(), cur.end());
        for (int j = 0; j < m; j++)
        {
            if (sum + cur[j] > h)
            {
                break;
            }
            sum += cur[j];
            pen += sum;
            tasks++;
        }
        if (i)
        {
            if (array<ll, 2>{-tasks, pen} < best)
            {
                ans++;
            }
        }
        else
        {
            best = {-tasks, pen};
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