#include <bits/stdc++.h>
using namespace std;

double p[121];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> p[i];
    }
    sort(p, p + 2 * n);
    double ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans *= 1 - (p[i] * p[2 * n - i - 1]);
    }
    cout << fixed << setprecision(9) << ans;
}