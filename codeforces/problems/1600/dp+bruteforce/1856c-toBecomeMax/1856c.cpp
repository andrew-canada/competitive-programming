#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3;

ll a[mxN + 1], tar[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll low = 0, high = *max_element(a, a + n) + k, ans = 0;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            bool good = false;

            for (int i = 0; i < n; i++)
            {
                tar[i] = mid;

                ll numUsed = 0;
                for (int j = i; j < n; j++)
                {
                    if (tar[j] <= a[j])
                    {
                        break;
                    }

                    if (j + 1 >= n)
                    {
                        numUsed = k + 1;
                        break;
                    }

                    numUsed += tar[j] - a[j];
                    tar[j + 1] = max(0LL, tar[j] - 1);
                }

                if (numUsed <= k)
                {
                    good = true;
                }
            }

            if (good)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << '\n';
    }
}