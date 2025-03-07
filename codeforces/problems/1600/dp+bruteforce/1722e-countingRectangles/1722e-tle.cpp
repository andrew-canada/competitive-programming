#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e5;

array<ll, 2> arr[mxN + 1];
ll prefArea[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            prefArea[i + 1] = prefArea[i] + arr[i][0] * arr[i][1];
        }

        ll hs, ws, hb, wb;
        for (int i = 0; i < q; i++)
        {
            cin >> hs >> ws >> hb >> wb;

            auto low = lower_bound(arr, arr + n, array<ll, 2>({hs + 1, 0LL}));
            auto high = upper_bound(arr, arr + n, array<ll, 2>({hb - 1, LLONG_MAX}));

            ll ans = 0;
            for (auto it = low; it != high; ++it)
            {
                if ((*it)[1] > ws && (*it)[1] < wb)
                {
                    ans += (*it)[0] * (*it)[1];
                }
            }

            cout << ans << '\n';
        }
    }
}