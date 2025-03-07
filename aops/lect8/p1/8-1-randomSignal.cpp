#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int rp, cp, rg, cg;
    cin >> rp >> cp >> rg >> cg;

    double ans = 0;
    int nrp = rp, ncp = cp, i = 2;
    while (nrp <= rg && ncp <= cg)
    {
        ans += 1.0 * (rg - nrp + 1) * (cg - ncp + 1) / pow(2, nrp * ncp);
        nrp = rp * i, ncp = cp * i;
        ++i;
    }
    cout << fixed << setprecision(9) << ans;
}