#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double n, k;
    cin >> n >> k;
    double x = 1;
    double y = (k - 2) / k;
    for (int i = 0; i < n; ++i)
    {
        x *= y;
    }
    double numer = 1 - x;
    double denom = 1 - y;
    cout << fixed << setprecision(6) << (numer / denom) << '\n';
}