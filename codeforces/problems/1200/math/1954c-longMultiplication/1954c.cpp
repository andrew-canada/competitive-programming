#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    string x, y;
    cin >> x >> y;
    bool ok = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > y[i] == ok)
        {
            swap(x[i], y[i]);
        }
        ok |= (x[i] != y[i]);
    }
    cout << x << '\n'
         << y << '\n';
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