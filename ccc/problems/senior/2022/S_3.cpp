#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6;

int ans[mxN + 1];

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll ns = k - n;
    if (ns < 0)
    {
        cout << "-1\n";
        return 0;
    }
    int val = 1;
    while (val <= m && val <= n)
    {
        if (ns - val + 1 >= 0)
        {
            ans[val - 1] = val;
            ns = ns - val + 1;
        }
        else
        {
            break;
        }
        val++;
    }
    for (int i = val - 1; i < n; i++)
    {
        if (ns)
        {
            for (int j = m; j >= 1; j--)
            {
                if (ns - j + 1 >= 0)
                {
                    ns = ns - j + 1;
                    ans[i] = ans[i - j];
                    break;
                }
            }
        }
        else
        {
            ans[i] = ans[i - 1];
        }
    }
    if (ns == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "-1\n";
    }
}