#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    double p = 1.0 * n / k;
    double rem = p * (1 - 1.0 / k);

    cout << fixed << setprecision(6) << k * rem;
}
