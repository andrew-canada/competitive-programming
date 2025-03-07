#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll v;
ll a[mxN + 1], sums[mxN + 1];

vector<int> getPref(int n)
{
    vector<int> pref(n + 1, 0);
    int end = 0, val = 0;
    ll sum = 0;
    for (int start = 0; start < n; start++)
    {
        while (end < n && sum < v)
        {
            sum += a[end];
            ++end;
            pref[end] = max(pref[end], pref[end - 1]);
        }
        if (sum >= v)
        {
            pref[end] = 1 + pref[start];
        }
        sum -= a[start];
    }
    for (int i = 1; i <= n; i++)
    {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    return pref;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m >> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            sums[i + 1] = sums[i] + a[i];
        }

        auto pref = getPref(n);
        reverse(a, a + n);
        auto suf = getPref(n);
        reverse(a, a + n);
        reverse(suf.begin(), suf.end());

        if (pref[n] < m)
        {
            cout << "-1\n";
            continue;
        }

        int end = 0;
        ll ans = 0;
        for (int start = 0; start < n; start++)
        {
            while (end < n && pref[start] + suf[end + 1] >= m)
            {
                ++end;
            }
            if (pref[start] + suf[end] >= m)
            {
                ans = max(ans, sums[end] - sums[start]);
            }
        }
        cout << ans << "\n";
    }
}