#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int m, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> m >> a >> b >> c;
        int r1 = (a > m ? m : a), r2 = (b > m ? m : b);
        int rem = 2 * m - r1 - r2;
        int misc = (c > rem ? rem : c);
        cout << r1 + r2 + misc << '\n';
    }
}