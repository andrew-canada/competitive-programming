#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll n, ll k)
{
    ll ans = 0;
    stack<array<ll, 2>> seg;
    seg.push({1, n});

    while (!seg.empty())
    {
        auto [l, r] = seg.top();
        seg.pop();

        if (r - l + 1 < k)
        {
            continue;
        }

        ll m = (l + r) / 2;
        if ((r - l + 1) % 2 == 1)
        {
            ans += m;
            if (l <= m - 1)
            {
                seg.push({l, m - 1});
            }
            if (m + 1 <= r)
            {
                seg.push({m + 1, r});
            }
        }
        else
        {
            seg.push({l, m});
            seg.push({m + 1, r});
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
}