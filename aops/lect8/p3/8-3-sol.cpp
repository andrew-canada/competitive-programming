#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    double pis[2 * n];
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> pis[i];
    }
    // We need to do this before iterating through permutations!
    sort(pis, pis + 2 * n);
    double success_prob = 1.0;
    for (int i = 0; i < n; ++i)
    {
        success_prob *= (1.0 - (pis[i] * pis[2 * n - 1 - i]));
    }
    cout << fixed << setprecision(9) << success_prob << '\n';
}