#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        for (int a1 = a; a1 < b; a1++)
        {
            int b1 = 0;
            int binv = ((1 << 21) - 1) ^ b;
            int fir = binv & a1;
            if (fir == 0)
            {
                b1 = b;
            }
            else
            {
                int bt = 31 - __builtin_clz(fir);
                int bnew = (b >> (bt + 1)) << (bt + 1);
                b1 = bnew;
                b1 ^= (1 << bt);
            }
            ans = min(ans, a1 - a - b + (a1 | b1) + 1);
        }
        cout << ans << '\n';
    }
}