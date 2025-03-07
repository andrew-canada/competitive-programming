#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ll l, r, g;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> g;

        if (g > r)
        {
            cout << "-1 -1\n";
            continue;
        }

        ll a = (l + g - 1) / g * g;
        ll b = r / g * g;

        if (a < l || a > r || b > r || b < l)
        {
            cout << "-1 -1\n";
        }
        else
        {
            cout << a << " " << b << "\n";
        }
    }
}