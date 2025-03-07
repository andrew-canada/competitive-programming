#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 524288;

int tree[mxN * 2];
ll ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, l, r, m, ti;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        l = 1, r = n, ti = 1;
        while (l != r)
        {
            m = (l + r) / 2;
            if (x <= m)
            {
                ti *= 2;
                r = m;
            }
            else
            {
                ti = ti * 2 + 1;
                l = m + 1;
                ans += tree[ti - 1];
            }
            tree[ti / 2]++;
        }
        tree[ti]++;
    }
    cout << ans;
}