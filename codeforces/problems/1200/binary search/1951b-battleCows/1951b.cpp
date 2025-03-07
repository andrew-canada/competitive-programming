#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k, ans = 0, mxIdx = -1;
    cin >> n >> k;
    --k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (k == 0)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= a[k])
            {
                break;
            }
            ans = i;
        }
        cout << ans << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[k])
        {
            mxIdx = i;
            break;
        }
        ans = i;
    }
    if (mxIdx == k)
    {
        for (int i = mxIdx + 1; i < n; i++)
        {
            if (a[i] >= a[k])
            {
                break;
            }
            ans++;
        }
        cout << ans + 1 << '\n';
        return;
    }
    for (int i = mxIdx + 1; i < n; i++)
    {
        if (a[i] >= a[k])
        {
            break;
        }
        ans = max(ans, i - mxIdx + (mxIdx > 0));
    }
    cout << max(ans, (int)(mxIdx > 0)) << '\n';
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

// 1624956809NT
// 12/24/1935