#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define ar array
#define pb push_back
#define ln '\n'
#define size(x) (int)(x).size()
#define int long long

typedef pair<int, int> pii;

using i64 = long long;

template <class F, class _S>
bool chmin(F &u, const _S &v)
{
    bool flag = false;
    if (u > v)
    {
        u = v;
        flag |= true;
    }
    return flag;
}

template <class F, class _S>
bool chmax(F &u, const _S &v)
{
    bool flag = false;
    if (u < v)
    {
        u = v;
        flag |= true;
    }
    return flag;
}

void solve()
{
    int l, r, g;
    cin >> l >> r >> g;

    l = (l + g - 1) / g, r /= g;

    if (l >= r && l != 1)
        return cout << "-1 -1\n", void();

    for (int len = r - l + 1; len >= 0; len--)
    {
        for (int j = l; j + len <= r; j++)
        {
            if (__gcd(j, j + len) == 1)
                return cout << j * g << ' ' << (j + len) * g << '\n', void();
        }
    }
    cout << "-1 -1\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    cout << '\n';
}