#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    int num1 = m % k, numK = m / k;
    int fancy1 = max(0, num1 - a1), fancyK = max(0, numK - ak);
    int l = max(0, a1 - num1), rep = min(l / k, fancyK);
    cout << fancy1 + fancyK - rep << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}