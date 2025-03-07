#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k, ans = INF, cur;
    cin >> n >> k;
    vector<int> c(n), last(k, -1), oneStep(k), twoStep(k);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cur = i - last[c[i] - 1];
        if (cur > oneStep[c[i] - 1])
        {
            twoStep[c[i] - 1] = oneStep[c[i] - 1];
            oneStep[c[i] - 1] = cur;
        }
        else if (cur > twoStep[c[i] - 1])
        {
            twoStep[c[i] - 1] = cur;
        }
        last[c[i] - 1] = i;
    }
    for (int i = 0; i < k; i++)
    {
        cur = n - last[i];
        if (cur > oneStep[i])
        {
            twoStep[i] = oneStep[i];
            oneStep[i] = cur;
        }
        else if (cur > twoStep[i])
        {
            twoStep[i] = cur;
        }
    }
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, max((oneStep[i] + 1) / 2, twoStep[i]));
    }
    cout << ans - 1 << '\n';
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