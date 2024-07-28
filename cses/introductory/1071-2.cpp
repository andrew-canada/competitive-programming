#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        ll msl = max(r, c);
        ll ans = (msl - 1) * (msl - 1);
        if (msl & 1)
        {
            if (msl == r)
            {
                ans += c;
            }
            else
            {
                ans += 2 * msl - r;
            }
        }
        else
        {
            if (msl == r)
            {
                ans += 2 * msl - c;
            }
            else
            {
                ans += r;
            }
        }
        cout << ans << '\n';
    }
}