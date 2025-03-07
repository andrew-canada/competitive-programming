#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

int t, n, k;
array<ll, 2> arr[mxN + 1];

array<ll, 2> getNeg(ll price)
{
    ll ans = 0, tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (price > arr[i][0] && price <= arr[i][1])
        {
            ans++;
        }
        if (price <= arr[i][1])
        {
            tot++;
        }
    }
    return {ans, tot};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll low = 2e9 + 1, high = -1, mid;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0];
            low = min(low, arr[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][1];
            high = max(high, arr[i][1]);
        }
        ll ans = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            array<ll, 2> res = getNeg(mid);
            if (res[0] > k)
            {
                high = mid - 1;
            }
            else
            {
                low = high + 1;
                ans = res[1];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}