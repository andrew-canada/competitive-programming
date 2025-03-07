#include <bits/stdc++.h>

using namespace std;

#define int long long

int pgcd(int a, int b)
{
    if (b == 0)
        return a;
    return pgcd(b, a % b);
}

int ppcm(int a, int b)
{
    return (a * b) / pgcd(a, b);
}

void solve()
{

    int n, k;
    cin >> n >> k;

    vector<int> occ[k];

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        occ[x % k].push_back(i);
    }

    for (int i = 0; i < k; i++)
    {
        if (occ[i].size() == 1)
        {
            cout << "YES\n";
            cout << occ[i][0] << '\n';
            return;
        }
    }

    cout << "NO\n";
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
