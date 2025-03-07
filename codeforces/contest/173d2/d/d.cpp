#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    ll l, r, g;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> g;
        l = (l + g - 1) / g, r /= g;
        if (l >= r && l != 1)
        {
            cout << "-1 -1\n";
            continue;
        }

        bool found = false;
        for (ll len = r - l + 1; len >= 0; len--)
        {
            for (ll j = l; j + len <= r; j++)
            {
                if (__gcd(j, j + len) == 1)
                {
                    cout << j * g << ' ' << (j + len) * g << '\n';
                    found = true;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        if (found)
        {
            continue;
        }
        cout << "-1 -1\n";
    }
}